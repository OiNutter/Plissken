#include <Python.h>
#include "lib/houdini.h"

typedef int (*houdini_cb)(gh_buf *, const uint8_t *, size_t);

/**
* html_secure instance variable
*/
static int g_html_secure = 1;

static PyObject *
plissken__generic_escape(houdini_cb do_escape,PyObject *args)
{
    const char *str;
    gh_buf buf = GH_BUF_INIT;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    if (do_escape(&buf, (const uint8_t *)str, sizeof(str))) {
        PyObject *result = Py_BuildValue("s",buf.ptr);
        return result;
    }

    return Py_BuildValue("s",str);
}

static PyObject *
plissken_escape_html(PyObject *self, PyObject *args)
{
	const char *str;
	gh_buf buf = GH_BUF_INIT;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    if (houdini_escape_html0(&buf, (const uint8_t *)str, sizeof(str),g_html_secure)) {
		PyObject *result = Py_BuildValue("s",buf.ptr);
		return result;
	}

	return Py_BuildValue("s",str);
}

static PyObject *
plissken_unescape_html(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_unescape_html,args);
}

static PyObject *
plissken_escape_js(PyObject *self, PyObject *args)
{
    return plissken__generic_escape(&houdini_escape_js,args);
}

static PyObject *
plissken_unescape_js(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_unescape_js,args);
}

static PyObject *
plissken_escape_uri(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_escape_uri,args);
}

static PyObject *
plissken_unescape_uri(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_unescape_uri,args);
}

static PyObject *
plissken_escape_xml(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_escape_xml,args);
}

static PyObject *
plissken_escape_href(PyObject *self, PyObject *args)
{
   return plissken__generic_escape(&houdini_escape_href,args);
}

static PyMethodDef PlisskenMethods[] = {
    { "escape_html",  plissken_escape_html, METH_VARARGS, "Escape an HTML string." },
    { "unescape_html",  plissken_unescape_html, METH_VARARGS, "Unescape an HTML string." },
    { "escape_js",  plissken_escape_js, METH_VARARGS, "Escape a JS string." },
    { "unescape_js",  plissken_unescape_js, METH_VARARGS, "Unescape a JS string." },
    { "escape_uri",  plissken_escape_uri, METH_VARARGS, "Escape a URI string." },
    { "unescape_uri",  plissken_unescape_uri, METH_VARARGS, "Unescape a URI string." },
    { "escape_xml",  plissken_escape_xml, METH_VARARGS, "Escape an XML string." },
    { "escape_href",  plissken_escape_href, METH_VARARGS, "Escape an HREF string." },
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initplissken(void)
{
    (void) Py_InitModule("plissken", PlisskenMethods);
}

int
main(int argc, char *argv[])
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initplissken();

    return 1;

}