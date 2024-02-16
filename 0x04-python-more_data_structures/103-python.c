#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p)
{
	if (!PyList_Check(p))
	{
		fprintf(stderr, "Invalid PyListObject\n");
		return;
	}

	Py_ssize_t size = PyList_Size(p);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %zd\n", size);
	printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

	for (Py_ssize_t i = 0; i < size; ++i)
	{
		PyObject *item = PyList_GetItem(p, i);
		const char *type = item->ob_type->tp_name;

		printf("Element %zd: %s\n", i, type);
	}
}

void print_python_bytes(PyObject *p)
{
	if (!PyBytes_Check(p))
	{
		fprintf(stderr, "Invalid PyBytesObject\n");
		return;
	}

	Py_ssize_t size = PyBytes_Size(p);
	const char *data = PyBytes_AsString(p);

	printf("[.] bytes object info\n");
	printf("size: %zd\n", size);
	printf("trying string: %s\n", data);

	printf("first 10 bytes: ");
	for (Py_ssize_t i = 0; i < size && i < 10; ++i)
	{
		printf("%02hhx ", data[i]);
	}
	printf("\n");
}
