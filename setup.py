from distutils.core import setup, Extension

plissken = Extension('plissken',
                    sources = [
                    			'lib/buffer.c',
                    			'lib/houdini_href_e.c',
                    			'lib/houdini_html_e.c',
                    			'lib/houdini_html_u.c',
                    			'lib/houdini_js_e.c',
                    			'lib/houdini_js_u.c',
                    			'lib/houdini_uri_e.c',
                    			'lib/houdini_uri_u.c',
                    			'lib/houdini_xml_e.c',
                    			'plissken.c'
                    		]
                    	)

setup (name = 'Plissken',
       version = '0.1',
       description = 'Python wrapper for the C Houdini escape library',
       ext_modules = [plissken])