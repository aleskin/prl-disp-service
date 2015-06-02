from insn import *
insn_descs = [
	insn_desc('FXSAVE', [Op('mem', 0)], [Byte(0xf), Byte(0xae), ModRM(0, mod = [0])], set(['SSE', 'FPU', 'X64', 'REX.W']), 64,
				[
					('RSP', [0x2800]),
					('RBX', [0x4000 - i for i in range(1024)]),
					('XCR0', [1, 3, 7])
				]),

	insn_desc('FXSAVE64', [Op('mem', 0)], [Byte(0x48), Byte(0xf), Byte(0xae), ModRM(0, mod = [0])], set(['SSE', 'FPU', 'X64', 'REX.W']), 64,
				[
					('RSP', [0x2800]),
					('RBX', [0x4000 - i for i in range(1024)]),
					('XCR0', [1, 3, 7])
				]),

	insn_desc('XSAVE64', [Op('mem', 0)], [Byte(0x48), Byte(0xf), Byte(0xae), ModRM(4, mod = [0])], set(['REX.W', 'LONG', 'NEHALEM']), 64,
				[
					('RSP', [0x2800]),
					('RAX', range(8)),
					('RDX', [0, 1]),
					('RBX', [0x4000 - i for i in range(1024)]),
					('XCR0', [1, 3, 7])
				]),

	insn_desc('FXRSTOR', [Op('mem', 0)], [Byte(0xf), Byte(0xae), ModRM(1, mod = [0])], set(['SSE', 'FPU', 'X64', 'REX.W']), 64,
				[
					('cr0', [0x0, 0x4, 0x8, 0xc]),
					('fcw', [0x0, 0x37f]),
					('fsw', [0x0, 0xc00, 0x1, 0xc01]),
					('ftw', [0x0, 0x1f]),
					('RSP', [0x2800]),
					('RBX', [0x3000]),
					('XCR0', [1, 3, 7]),

					(0, XSTATE())
				]
	),

	insn_desc('FXRSTOR64', [Op('mem', 0)], [Byte(0x48), Byte(0xf), Byte(0xae), ModRM(1, mod = [0])], set(['SSE', 'FPU', 'X64', 'REX.W']), 64,
				[
					('cr0', [0x0, 0x4, 0x8, 0xc]),
					('fcw', [0x0, 0x37f]),
					('fsw', [0x0, 0xc00, 0x1, 0xc01]),
					('ftw', [0x0, 0x1f]),
					('RSP', [0x2800]),
					('RBX', [0x3000]),
					('XCR0', [1, 3, 7]),

					(0, XSTATE())
				]
	),

	insn_desc('XRSTOR', [Op('mem', 0)], [Byte(0xf), Byte(0xae), ModRM(5, mod = [0])], set(['REX.W', 'LONG', 'NEHALEM']), 64,
				[
					('cr0', [0x0, 0x4, 0x8, 0xc]),
					('fcw', [0x0, 0x37f]),
					('fsw', [0x0, 0xc00, 0x1, 0xc01]),
					('ftw', [0x0, 0x1f]),
					('RSP', [0x2800]),
					('RBX', [0x3000]),
					('RAX', range(7)),
					('RDX', [0]),
					('XCR0', [1, 3, 7]),

					(0, XSTATE(XSTATE_BV = range(7)))
				]
	),


	insn_desc('XRSTOR64', [Op('mem', 0)], [Byte(0x48), Byte(0xf), Byte(0xae), ModRM(5, mod = [0])], set(['REX.W', 'LONG', 'NEHALEM']), 64,
				[
					('cr0', [0x0, 0x4, 0x8, 0xc]),
					('fcw', [0x0, 0x37f]),
					('fsw', [0x0, 0xc00, 0x1, 0xc01]),
					('ftw', [0x0, 0x1f]),
					('RSP', [0x2800]),
					('RBX', [0x3000]),
					('RAX', range(7)),
					('RDX', [0]),
					('XCR0', [1, 3, 7]),

					(0, XSTATE(XSTATE_BV = range(7)))
				]
	),

	insn_desc('LDMXCSR', [Op('mem', 32)], [Prefixes(), Byte(0xf), Byte(0xae), ModRM(2, mod = [0])], set(['SSE', 'KATMAI']), 32, [('RBX', [0x3000, 0x3ffe, 0x12fff, 0x8000000000003000L]), (0x0, [0x0, 0x1, 0x80000000, 0x80000001]), ('mxcsr', [0x0, 0x80, 0x100, 0x180, 0x200, 0x280, 0x300]), ('fcw', [0x0, 0x37f]), ('fsw', [0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f]), ('xcr0', [0x1, 0x3, 0x7]), ('RSP', [0x2800])]),

	insn_desc('STMXCSR', [Op('mem', 32)], [Prefixes(), Byte(0xf), Byte(0xae), ModRM(3, mod = [0])], set(['SSE', 'KATMAI']), 32, [('RBX', [0x3000, 0x12fff, 0x8000000000003000L]), (0x0, [0x0, 0x1, 0x80000000, 0x80000001]), ('mxcsr', [0x0, 0x80, 0x100, 0x180, 0x200, 0x280, 0x300]), ('fcw', [0x0, 0x37f]), ('fsw', [0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f]), ('xcr0', [0x1, 0x3, 0x7]), ('RSP', [0x2800])])
]
