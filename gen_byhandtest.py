"""
Test script for generating a wrapper for the code in autogentest.h by hand.
"""

import sys
import os

from pybindgen import ReturnValue, Parameter, Module, Function, FileCodeSink
from pybindgen import CppMethod, CppConstructor, CppClass, Enum

import pybindgen.settings
pybindgen.settings.automatic_type_narrowing = True

NAME = 'byhandtest'
SRC  = 'autogentest.h'
DEST = 'byhandtest_wrap.cpp'


def my_module_gen():
    module = Module(NAME)
    module.add_include('"%s"' % SRC)
    
    A = module.add_class('A', allow_subclassing=True)
    A.add_constructor([])
    A.add_method('virtualMethod1', None, [], is_virtual=True, is_pure_virtual=True)
    A.add_method('virtualMethod2', None, [], is_virtual=True)


    
    B = module.add_class('B', parent=A)
    B.add_constructor([])
    B.add_constructor([Parameter.new('int', 'a'), Parameter.new('int', 'b')])
    B.add_method('virtualMethod1', None, [], is_virtual=True)
        
    B.add_method('overloadedMethod', None, [])
    B.add_method('overloadedMethod', None, [Parameter.new('int', 'a'), Parameter.new('int', 'b')])
    B.add_method('overloadedMethod', None, [Parameter.new('double', 'd')])
           
    B.add_method('defaultArgs', None, [Parameter.new('int', 'a', default_value='0'), 
                                       Parameter.new('int', 'b', default_value='123')])

    #bool operator==(const B& other) { return false; }
    #bool operator!=(const B& other) { return true; }

    #B& operator+(const B& other) { return *this; }

    #// anything special done for these?
    #int __len__() { return 0; }  // yes, added to sequence methods structure
    #int __int__() { return 0; }  // no but the method is still there
    
    #operator bool() { return true; } // no
    
    #static void staticMethod() {}
    
    #int m_publicAttribute;
                                


    C = module.add_class('C', parent=B)
    B.add_constructor([])
    B.add_constructor([Parameter.new('int', 'a'), Parameter.new('int', 'b')])
    B.add_method('returnBaseClassPtr', ReturnValue.new('A*',
                                                       #caller_owns_return=True
                                                       reference_existing_object=True
                                                       ), [])
        
    #A* returnBaseClassPtr() { return this; }    
    #void baseClassParameterPtr(const A* ptr) {}
    #void baseClassParameterRef(const A& ptr) {}

    
    output = open(DEST, 'w')
    module.generate(FileCodeSink(output))

if __name__ == '__main__':
    my_module_gen()
