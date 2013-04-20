from distutils.core import setup, Extension

module1 = Extension('plissken',
                    sources = ['plissken.c'])

setup (name = 'Plissken',
       version = '0.1',
       description = 'Python wrapper for the C Houdini escape library',
       ext_modules = [module1])