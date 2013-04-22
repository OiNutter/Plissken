#include <Python.h>
#include "lib/houdini.h"

/**
* html_secure instance variable
*/
static int g_html_secure = 1;

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
    const char *str;
    gh_buf buf = GH_BUF_INIT;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;

    if (houdini_unescape_html(&buf, (const uint8_t *)str, sizeof(str))) {
        PyObject *result = Py_BuildValue("s",buf.ptr);
        return result;
    }

    return Py_BuildValue("s",str);
}

static PyMethodDef PlisskenMethods[] = {
    { "escape_html",  plissken_escape_html, METH_VARARGS, "Escape an HTML string." },
    { "unescape_html",  plissken_unescape_html, METH_VARARGS, "Unescape an HTML string." },
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