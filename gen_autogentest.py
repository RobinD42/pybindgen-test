"""
Test script for generating a wrapper for the code in testclasses.h using gccxml.
"""

import sys
import os

import pybindgen
from pybindgen import FileCodeSink
from pybindgen.gccxmlparser import ModuleParser

NAME = 'autogentest'
SRC = 'autogentest.h'
DEST = 'autogentest_wrap.cpp'

# TODO: look for this on the PATH, for now I've just installed it in my VirtualEnv
GCCXML = os.path.join(sys.prefix, 'bin', 'gccxml')  


def my_module_gen():
    module_parser = ModuleParser(NAME)
    module = module_parser.parse(
        [SRC], gccxml_options=dict(gccxml_path=GCCXML))
    module.add_include('"%s"' % SRC)

    output = open(DEST, 'w')
    pybindgen.write_preamble(FileCodeSink(output))
    module.generate(FileCodeSink(output))

if __name__ == '__main__':
    my_module_gen()
