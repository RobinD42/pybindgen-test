import sys, os, os.path
from setuptools import setup, Extension

autogentest = Extension('autogentest', 
                        sources=['autogentest_wrap.cpp'],
                        #include_dirs=[],
                        )

byhandtest = Extension('byhandtest', 
                        sources=['byhandtest_wrap.cpp'],
                        #include_dirs=[],
                        )

setup( name = "pybindgen-test",
       version = "1.0.0",
       description = "My testing modules for pybindgen",
       author = "Robin Dunn",
       author_email = "rdunn@enthought.com",
       
       ext_modules = [autogentest, 
                      byhandtest,
                      ],
)
