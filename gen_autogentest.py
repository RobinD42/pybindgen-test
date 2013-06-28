"""
Test script for generating a wrapper for the code in testclasses.h using gccxml.
"""

import sys

import pybindgen
from pybindgen import FileCodeSink
from pybindgen.gccxmlparser import ModuleParser

NAME = 'testclasses'
SRC = 'testclasses.h'
DEST = 'testclasses_wrap.cpp'

def my_module_gen():
    module_parser = ModuleParser(NAME)
    module = module_parser.parse([SRC], 
                                 gccxml_options=dict(gccxml_path='./PyVE/bin/gccxml'))
    module.add_include('"%s"' % SRC)

    output = open(DEST, 'w')
    pybindgen.write_preamble(FileCodeSink(output))
    module.generate(FileCodeSink(output))

if __name__ == '__main__':
    my_module_gen()
