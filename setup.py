from distutils.core import setup, Extension

plissken = Extension('plissken',
					libraries=["houdini"],
					library_dirs=["lib"],
                    sources = [
                    			'plissken.c'
                    		]
                    	)

setup (name = 'Plissken',
       version = '0.1',
       description = 'Python wrapper for the C Houdini escape library',
       ext_modules = [plissken])