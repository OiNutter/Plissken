Plissken
========

![Snake Plissken](https://github.com/OiNutter/Plissken/raw/master/snaaaaaaaaake.jpeg)

Plissken is a python wrapper for the [Houdini](https://github.com/vmg/houdini) string escaping library.

Install
-------

```bash
$ pip install plissken
```

Usage
-----

```python
import plissken

plissken.escape_html('&')
# >> &amp;

plissken.unescape_html('&amp;')
# >> &

plissken.escape_xml('')
# >>

plissken.unescape_uri('')
# >>

plissken.escape_url('')
# >>

plissken.unescape_url('')
# >>

plissken.escape_href('')
# >>

plissken.escape_js('"')
# >> \"

plissken.unescape_js('\"')
# >> "

```

Contributing
------------

Just fork, commit and submit!

Credits
-------

@vmg for the [Houdini](https://github.com/vmg/houdini) library and @brianmario for his [escape_utils](https://github.com/brianmario/escape_utils) gem, which was really helpful in figuring out the required C code to interface with Houdini
