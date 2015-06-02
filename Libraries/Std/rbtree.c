/*
 * Copyright (c) 2015 Parallels IP Holdings GmbH
 *
 * This file is part of Virtuozzo Core Libraries. Virtuozzo Core
 * Libraries is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#include <Interfaces/ParallelsTypes.h>
#include "rbtree.h"

/*
 * Good description of RB trees can be found e.g. in a popular CS book
 * Thomas H. Cormen, Charles E. Leiserson, and Ronald L. Rivest.
 * Introduction to Algorithms.
 *
 * Obviously Maximum() and Minimum() operations can be done via
 * rb_first(), rb_last().
 *
 * COMPLEXITY: Search, Insert, Delet, First, Last, Next, Prev are all O(log n)
 *
 */

/* rb_parent field is used for parent:31 + color:1 store */
#define rb_parent(n)	((struct rb_node *)((n)->rb_parent & ~1))
#define rb_color(n)		((ULONG_PTR)((n)->rb_parent & 1))

#define rb_set_red(n)	do {(n)->rb_parent &= ~1;} while (0)
#define rb_set_black(n)	do {if (n) (n)->rb_parent |= 1;} while (0)

#define rb_is_red(n)	( (n) && !rb_color(n))
#define rb_is_black(n)	(!(n) || rb_color(n))

#undef RB_DEBUG

#ifdef RB_DEBUG
#define rb_debug(msg) printf(msg)
#else
#define rb_debug(msg) do { ; } while (0)
#endif

static inline void rb_set_parent(struct rb_node *n, struct rb_node *p)
{
	if (!n)
		return;
	n->rb_parent = rb_color(n) | (ULONG_PTR)p;
}
static inline void rb_set_color(struct rb_node *n, ULONG_PTR color)
{
	n->rb_parent = color | (ULONG_PTR)rb_parent(n);
}

static void left_rotate(struct rb_root *root, struct rb_node *node)
{
	struct rb_node *right;
	struct rb_node *parent;

	right = node->rb_right;
	node->rb_right = right->rb_left;
	rb_set_parent(right->rb_left, node);

	parent = rb_parent(node);
	rb_set_parent(right, parent);

	if (!parent) {
		root->rb_node = right;
	} else {
		if (node == parent->rb_left)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}

	right->rb_left = node;
	rb_set_parent(node, right);
}

static void right_rotate(struct rb_root *root, struct rb_node *node)
{
	struct rb_node *left;
	struct rb_node *parent;

	left = node->rb_left;
	node->rb_left = left->rb_right;
	rb_set_parent(left->rb_right, node);

	parent = rb_parent(node);
	rb_set_parent(left, parent);

	if (!parent) {
		root->rb_node = left;
	} else {
		if (node == parent->rb_right)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}

	left->rb_right = node;
	rb_set_parent(node, left);
}

static __inline struct rb_node *rb_insert_fixup_left(
		struct rb_root *root, struct rb_node *node,
		struct rb_node *parent, struct rb_node *parent2)
{
	struct rb_node *y = parent2->rb_right;

	if (rb_is_red(y))
	{
		rb_set_black(parent);
		rb_set_black(y);
		rb_set_red(parent2);
		node = parent2;
		return node;
	}

	if (node == parent->rb_right)
	{
		node = parent;
		left_rotate(root, node);
		parent = rb_parent(node);
		parent2 = rb_parent(parent);
	}

	rb_set_black(parent);
	rb_set_red(parent2);
	right_rotate(root, parent2);
	return node;
}

static __inline struct rb_node *rb_insert_fixup_right(
		struct rb_root *root, struct rb_node *node,
		struct rb_node *parent, struct rb_node *parent2)
{
	struct rb_node *y = parent2->rb_left;

	if (rb_is_red(y))
	{
		rb_set_black(parent);
		rb_set_black(y);
		rb_set_red(parent2);
		node = parent2;
		return node;
	}

	if (node == parent->rb_left)
	{
		node = parent;
		right_rotate(root, parent);
		parent = rb_parent(node);
		parent2 = rb_parent(parent);
	}

	rb_set_black(parent);
	rb_set_red(parent2);
	left_rotate(root, parent2);
	return node;
}

void rb_insert_fixup(struct rb_root *root, struct rb_node *node)
{
	struct rb_node *parent, *parent2;

	while (node != root->rb_node && rb_is_red(parent = rb_parent(node)))
	{
		parent2 = rb_parent(parent);

		if (parent == parent2->rb_left)
			node = rb_insert_fixup_left(root, node, parent, parent2);
		else
			node = rb_insert_fixup_right(root, node, parent, parent2);
	}

	rb_set_black(root->rb_node);
}

static __inline void rb_delete_fixup_left(struct rb_node **pnode, struct rb_node **pparent,
		                 struct rb_root *root)
{
	struct rb_node *neigh;
	struct rb_node *parent = *pparent;

	neigh = parent->rb_right;
	if (rb_is_red(neigh))
	{
		rb_set_black(neigh);
		rb_set_red(parent);
		left_rotate(root, parent);
		neigh = parent->rb_right;
	}

	if (rb_is_black(neigh->rb_left) && rb_is_black(neigh->rb_right))
	{
		rb_set_red(neigh);
		*pnode = parent;
		*pparent = rb_parent(parent);
		return;
	}

	if (rb_is_black(neigh->rb_right))
	{
		rb_set_black(neigh->rb_left);
		rb_set_red(neigh);
		right_rotate(root, neigh);
		neigh = parent->rb_right;
	}
	rb_set_color(neigh, rb_color(parent));
	rb_set_black(parent);
	rb_set_black(neigh->rb_right);
	left_rotate(root, parent);

	*pnode = root->rb_node;
}

static __inline void rb_delete_fixup_right(struct rb_node **pnode, struct rb_node **pparent,
		                 struct rb_root *root)
{
	struct rb_node *neigh;
	struct rb_node *parent = *pparent;

	neigh = parent->rb_left;
	if (rb_is_red(neigh))
	{
		rb_set_black(neigh);
		rb_set_red(parent);
		right_rotate(root, parent);
		neigh = parent->rb_left;
	}

	if (rb_is_black(neigh->rb_left) && rb_is_black(neigh->rb_right))
	{
		rb_set_red(neigh);
		*pnode = parent;
		*pparent = rb_parent(parent);
		return;
	}

	if (rb_is_black(neigh->rb_left))
	{
		rb_set_black(neigh->rb_right);
		rb_set_red(neigh);
		left_rotate(root, neigh);
		neigh = parent->rb_left;
	}

	rb_set_color(neigh, rb_color(parent));
	rb_set_black(parent);
	rb_set_black(neigh->rb_left);
	right_rotate(root, parent);

	*pnode = root->rb_node;
}

static void rb_delete_fixup(struct rb_node *node, struct rb_node *parent,
			     struct rb_root *root)
{
	while (rb_is_black(node) && node != root->rb_node)
	{
		if (parent->rb_left == node)
			rb_delete_fixup_left(&node, &parent, root);
		else
			rb_delete_fixup_right(&node, &parent, root);
	}

	rb_set_black(node);
}

static __inline void rb_cut(struct rb_root *root, struct rb_node *node, struct rb_node *child)
{
	struct rb_node *parent;

	parent = rb_parent(node);
	rb_set_parent(child, parent);

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = child;
		else if (parent->rb_right == node)
			parent->rb_right = child;
		else
			rb_debug("corrupted rbtree on delete");
	} else
		root->rb_node = child;
}

static __inline void rb_delete_simple(struct rb_root *root, struct rb_node *node)
{
	struct rb_node *child = NULL;
	struct rb_node *parent = NULL;

	if (!node->rb_left)
		child = node->rb_right;
	else
		child = node->rb_left; // note: it's ok for child to be NULL

	parent = rb_parent(node);
	rb_cut(root, node, child);

	if (rb_is_black(node))
		rb_delete_fixup(child, parent, root);
}

static __inline void rb_delete_full(struct rb_root *root, struct rb_node *node)
{
	struct rb_node *orig = node, *left, *parent, *child;
	ULONG_PTR color;

	node = node->rb_right;
	while ((left = node->rb_left) != NULL)
		node = left;

	color = rb_color(node);
	child = node->rb_right;
	parent = rb_parent(node);
	if (parent == orig)
		parent = node;

	/* remove node first from the tree */
	rb_cut(root, node, child);

	/* then replace orig with removed node... */
	rb_cut(root, orig, node);
	node->rb_right = orig->rb_right;
	node->rb_left = orig->rb_left;
	node->rb_parent = orig->rb_parent; /* copy color */

	/* ... and link orig children to node */
	rb_set_parent(orig->rb_left, node);
	rb_set_parent(orig->rb_right, node);

	if (color == RBTREE_BLACK)
		rb_delete_fixup(child, parent, root);
}

void rb_delete(struct rb_root *root, struct rb_node *node)
{
	if (!node->rb_right || !node->rb_left)
		/* only one or no child present, simple to cut the node */
		rb_delete_simple(root, node);
	else
		rb_delete_full(root, node);
}

struct rb_node *rb_first(struct rb_root *root)
{
	struct rb_node *node = root->rb_node;

	if (!node)
		return NULL;

	while (node->rb_left)
		node = node->rb_left;

	return node;
}

struct rb_node *rb_last(struct rb_root *root)
{
	struct rb_node *node = root->rb_node;

	if (!node)
		return NULL;

	while (node->rb_right)
		node = node->rb_right;

	return node;
}

struct rb_node *rb_next(struct rb_node *node)
{
	struct rb_node *parent;

	if (node->rb_right) {
		node = node->rb_right;
		/* go left as far as we can */
		while (node->rb_left)
			node = node->rb_left;
		return (struct rb_node *)node;
	} else {
		while ((parent = rb_parent(node)) && node == parent->rb_right)
			node = parent;
		return parent;
	}
}

struct rb_node *rb_prev(struct rb_node *node)
{
	struct rb_node *parent;

	if (node->rb_left) {
		node = node->rb_left;
		/* go right as far as we can */
		while (node->rb_right)
			node=node->rb_right;
		return (struct rb_node *)node;
	} else {
		while ((parent = rb_parent(node)) && node == parent->rb_left)
			node = parent;

		return parent;
	}
}

