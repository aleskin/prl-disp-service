#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim:ts=4:sw=4:expandtab
#
# GenStringify.py
#
# Copyright (C) 1999-2015 Parallels IP Holdings GmbH
#
# This file is part of Parallels SDK. Parallels SDK is free
# software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License,
# or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library.  If not, see
# <http://www.gnu.org/licenses/>.
#
# Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
# Schaffhausen, Switzerland.
#

import os, sys, string, re

# Full path of this python file module
__full_file_path__ = os.path.split( os.path.abspath(__file__) )[0]
if __full_file_path__ == '':
    __full_file_path__ = os.path.abspath( os.path.getcwd() )

ERRORS_FN = 'PrlErrorsValues'
EVENTS_FN = 'PrlEventsValues'
ENUMS_FN  = 'PrlEnums.h'

# Errors flags
PublicErrors = 1
PrivateErrors = 2
AllErrors = PublicErrors | PrivateErrors


SDK_HEADER_PATH = '/usr/include/prlsdk'

HEADER_FILE_HEADER = """/*
 * %(filename)s.h
 *
 * DO NOT EDIT THIS FILE !!!
 * it generated automatically from %(filename)s.txt
 * Please, do not modify header directly - instead use description text file.
 * call Sources/Gen.py or Sources/SDK/GenSdk.py to generate
 *
 * This file is part of Parallels SDK. Parallels SDK is free
 * software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
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
"""

STRINGIFY_CONSTS_FN = 'PrlStringifyConsts.cpp'
STRINGIFY_CASE_TMPL = '        CASE_VALUE_TO_STRING(%s);'
STRINGIFY_CONSTS_TMPL = """///////////////////////////////////////////////////////////////////////////////
///
/// @file %(filename)s
///
/// DO NOT EDIT THIS FILE !!!
/// it generated automatically from PrlErrorsValues.h and PrlEventsValues.h
///
/// This file is part of Parallels SDK. Parallels SDK is free
/// software; you can redistribute it and/or modify it under the
/// terms of the GNU Lesser General Public License as published by
/// the Free Software Foundation; either version 2.1 of the License,
/// or (at your option) any later version.
///
/// This library is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Lesser General Public License for more details.
///
/// You should have received a copy of the GNU Lesser General Public
/// License along with this library.  If not, see
/// <http://www.gnu.org/licenses/> or write to Free Software Foundation,
/// 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
///
/// Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
/// Schaffhausen, Switzerland.
///
/// Copyright (c) 1999-2015 Parallels IP Holdings GmbH.
///
///////////////////////////////////////////////////////////////////////////////

#include "PrlStringifyConsts.h"
#include "Libraries/Logging/Logging.h"
#include "Interfaces/ParallelsTypes.h"

#define CASE_VALUE_TO_STRING( r ) \
    case ((unsigned int) r) : return #r ;

#ifdef __cplusplus
extern "C" {
#endif

const char * PrlResultToString(unsigned int value)
{
    switch ( value )
    {
%(errors_case)s
        default:
            WRITE_TRACE(DBG_FATAL, "Unknown PRL_RESULT code %%p", (void*)(ULONG_PTR)value) ;
            break ;
    }
    return "Unknown" ;
}


/**
 * Small utility method to transform event type to string
 */
const char * EventTypeToString(unsigned int value)
{
    switch ( value )
    {
%(events_case)s
        default:
            WRITE_TRACE(DBG_FATAL, "Unknown PRL_EVENT_TYPE value %%p", (void*)(ULONG_PTR)value) ;
            break ;
    }

    return "Unknown" ;
}


/**
 * Small utility method to transform type to string
 */
const char * HandleTypeToString(unsigned int value)
{
    switch ( value )
    {
%(h_types_case)s
        default:
            WRITE_TRACE(DBG_FATAL, "Unknown PRL_HANDLE_TYPE value %%p", (void*)(ULONG_PTR)value) ;
            break ;
    }

    return "Unknown" ;
}

/**
 * Small utility method to transform type to string
 */
const char * VmStateToString(unsigned int value)
{
    switch ( value )
    {
%(vms_types_case)s
        default:
            WRITE_TRACE(DBG_FATAL, "Unknown VIRTUAL_MACHINE_STATE value %%p", (void*)(ULONG_PTR)value) ;
            break ;
    }

    return "Unknown" ;
}

/**
 * Small utility method to transform type to string
 */
const char * JobOperationCodeToString(unsigned int value)
{
    switch ( value )
    {
%(joc_types_case)s
        default:
            WRITE_TRACE(DBG_FATAL, "Unknown PRL_JOB_OPERATION_CODE value %%p", (void*)(ULONG_PTR)value) ;
            break ;
    }

    return "Unknown" ;
}

#ifdef __cplusplus
}
#endif

"""

def iterate_sequentially(*seqs):
    for s in seqs:
        for i in s:
            yield i

def parse_error_file(file_data, writer):

    def parser(data):
        def row(type, text):
            return (text, type)
        header = True
        for line in map(string.rstrip, data.splitlines()):
            if header and not line.startswith('#ifndef'):
                continue
            header = False
            if not line or line[0]!='#':
                yield (line, "")
                continue
            try:
                arr = line.split()
                if arr[1].startswith('PRL_') and arr[2].startswith('PRL_RESULT'):
                    yield row(arr[0], arr[1])
            except:
                print "!!!! invalid row: ", line
                raise

    for txt, row_type in parser(file_data):
        if row_type == '#define':
            writer.write_value(txt)

    return writer


def parse_event_file(file_data, writer):

    for line in map(string.rstrip, file_data.splitlines()):
        if not line.startswith(' PET_'):
            continue
        writer.write_value(line.split()[0])

    return writer


class header_writer(object):

    def __init__(self, dest_fn):
        self.header = []
        self.codes = []
        self.dest_filename = dest_fn

    def write_line(self, text="", custom_line = False):
        if custom_line:
            dfn = text.split()
            if len(dfn) >= 3 \
               and (dfn[0] == '#define' or (dfn[0] == '#' and dfn[1] == 'define') ) \
               and len(set(dfn) & set(self.codes)) == 0:
                return
        self.header.append(text)

    def write_value(self, code):
        if not code == '.skip':
            self.codes.append(code)
            self.cur_code = code
            self.align = ""

    def get_codes_case(self):
        for c in self.codes:
            yield STRINGIFY_CASE_TMPL % c

class events_writer(header_writer):
    pass

class errors_writer(header_writer):

    def __init__(self, dest_fn):
        super(errors_writer, self).__init__(dest_fn)
        self.errors = []

    def write_err(self, code):
        super(errors_writer, self).write_err(code)
        self.errors.append(code)

    def get_errors(self, format_tmpl):
        for c in self.errors:
            yield format_tmpl % c

class enums_writer(object):

    def __init__(self):
        self.enums = []
        self.last_value = 0

    def write_enum(self, name, value):
        try:
            value = int(value, 0)
            self.last_value = value
        except ValueError:
            if value:
                #ignore enum value copies (v1 = v2)
                return
            self.last_value += 1
        self.enums.append((name, self.last_value))

    def get_enums_case(self):
        for n,v in self.enums:
            yield STRINGIFY_CASE_TMPL % n
    get_codes_case = get_enums_case


def parse_enum_file(file_data, writer, prefix):

    enum_match = re.compile("\s*(%s[A-Z_0-9]+)\s*(=\s*(-?0?[Xx]?[0-9]+|[A-Za-z_]+),?|,?)" % prefix)

    for line in file_data.splitlines():
        m = enum_match.match(line)
        if not m:
            continue
        writer.write_enum(m.group(1), m.group(3))

    return writer


def read_file(file_name, path=''):
    file_name = path and os.path.join(path, file_name) or file_name
    return open(file_name).read()


def write_if_differ(new_data, dest_filename):
    if os.path.exists(dest_filename) and \
            new_data == read_file(dest_filename):
        print 'Skip writing %s, it not changed.' % dest_filename
        return False
    open(dest_filename, "w").write(new_data)
    return True

def write_source_file(errors, events, h_types, vms_types, joc_types, file_name):
    values = {
        'filename': os.path.basename(file_name),
        'errors_case': '\n'.join(errors.get_codes_case()),
        'events_case': '\n'.join(events.get_codes_case()),
        'h_types_case': '\n'.join(h_types.get_codes_case()),
        'vms_types_case': '\n'.join(vms_types.get_codes_case()),
        'joc_types_case': '\n'.join(joc_types.get_codes_case())
    }
    return write_if_differ(STRINGIFY_CONSTS_TMPL % values, file_name)

def get_errors():
    return parse_error_file(
        read_file( ERRORS_FN  + '.h', SDK_HEADER_PATH),
        errors_writer(os.path.join(SDK_HEADER_PATH, ERRORS_FN + '.h')))

def get_events():
    return parse_event_file(
        read_file(EVENTS_FN + '.h', SDK_HEADER_PATH),
        events_writer(os.path.join(SDK_HEADER_PATH, EVENTS_FN + '.h')))

def gen_string_consts():
    LIBSTD_PATH = __full_file_path__
    h_types = parse_enum_file(
        read_file(ENUMS_FN, SDK_HEADER_PATH),
        enums_writer(),
        'PHT_')
    vms_types = parse_enum_file(
        read_file(ENUMS_FN, SDK_HEADER_PATH),
        enums_writer(),
        'VMS_')
    joc_types = parse_enum_file(
        read_file(ENUMS_FN, SDK_HEADER_PATH),
        enums_writer(),
        'PJOC_')

    write_source_file(
        get_errors(),
        get_events(),
        h_types,
        vms_types,
        joc_types,
        os.path.join(LIBSTD_PATH, STRINGIFY_CONSTS_FN))

def main():
    try:
        gen_string_consts()
    except Exception, e:
        print e
        return 1
    return 0

if ( __name__ == '__main__' ):
    sys.exit( main() )
