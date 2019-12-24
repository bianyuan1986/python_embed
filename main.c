#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	PyObject *pName = NULL;
	PyObject *pModule = NULL;
	PyObject *pFunc = NULL;
	PyObject *pArgs = NULL;
	PyObject *pValue = NULL;
	int i = 0;
	int ret = 0;

	if( argc < 3 )
	{
		printf("Usage: %s moduleName funcName arg1 arg2 ...\n", argv[0]);
		return 1;
	}

	Py_Initialize();
	pName = PyString_FromString(argv[1]);
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	if( pModule == NULL )
	{
		PyErr_Print();
		printf("Failed to load module:%s\n", argv[1]);
		return 1;
	}
	pFunc = PyObject_GetAttrString(pModule, argv[2]);
	if( !pFunc || !PyCallable_Check(pFunc) )
	{
		printf("Cannot find function:%s\n", argv[2]);
		ret = 1;
		goto OUT;
	}
	pArgs = PyTuple_New(argc-3);
	for( i = 0; i < argc - 3; ++i)
	{
		pValue = PyInt_FromLong(atoi(argv[i+3]));
		if( !pValue )
		{
			printf("Cannot convert argument.\n");
			ret = 1;
			goto OUT;
		}
		PyTuple_SetItem(pArgs, i, pValue);
	}
	pValue = PyObject_CallObject(pFunc, pArgs);
	if( pValue != NULL )
	{
		printf("Result of call:%ld\n", PyInt_AsLong(pValue));
	}
	else
	{
		printf("Wrong!\n");
	}

OUT:
	if( pValue )
	{
		Py_DECREF(pValue);
	}
	if( pArgs )
	{
		Py_DECREF(pArgs);
	}
	if( pFunc )
	{
		Py_XDECREF(pFunc);
	}
	if( pModule )
	{
		Py_DECREF(pModule);
	}
	Py_Finalize();

	return ret;
}

