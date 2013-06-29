"""
Test script for generating a wrapper for the code in autogentest.h by hand.
"""

import sys
import os

from pybindgen import ReturnValue, Parameter, Module, Function, FileCodeSink
from pybindgen import CppMethod, CppConstructor, CppClass, Enum

NAME = 'byhandtest'
SRC = 'autogentest.h'
DEST = 'byhandtest_wrap.cpp'


def my_module_gen():
    module = Module(NAME)
    module.add_include('"%s"' % SRC)
    
    A = module.add_class('A', allow_subclassing=True)
    A.add_constructor([])
    A.add_method('virtualMethod1', None, [], is_virtual=True, is_pure_virtual=True)
    A.add_method('virtualMethod2', None, [], is_virtual=True)

        
    
    output = open(DEST, 'w')
    module.generate(FileCodeSink(output))

if __name__ == '__main__':
    my_module_gen()
