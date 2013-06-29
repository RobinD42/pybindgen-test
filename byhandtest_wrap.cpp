/* This file was generated by PyBindGen 0.16.0 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h>


#if PY_VERSION_HEX < 0x020400F0

#define PyEval_ThreadsInitialized() 1

#define Py_CLEAR(op)				\
        do {                            	\
                if (op) {			\
                        PyObject *tmp = (PyObject *)(op);	\
                        (op) = NULL;		\
                        Py_DECREF(tmp);		\
                }				\
        } while (0)


#define Py_VISIT(op)							\
        do { 								\
                if (op) {						\
                        int vret = visit((PyObject *)(op), arg);	\
                        if (vret)					\
                                return vret;				\
                }							\
        } while (0)

#endif



#if PY_VERSION_HEX < 0x020500F0

typedef int Py_ssize_t;
# define PY_SSIZE_T_MAX INT_MAX
# define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;

#endif


#if     __GNUC__ > 2
# define PYBINDGEN_UNUSED(param) param __attribute__((__unused__))
#elif     __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
# define PYBINDGEN_UNUSED(param) __attribute__((__unused__)) param
#else
# define PYBINDGEN_UNUSED(param) param
#endif  /* !__GNUC__ */

typedef enum _PyBindGenWrapperFlags {
   PYBINDGEN_WRAPPER_FLAG_NONE = 0,
   PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED = (1<<0),
} PyBindGenWrapperFlags;


#include "autogentest.h"
#include <typeinfo>
/* --- forward declarations --- */


typedef struct {
    PyObject_HEAD
    A *obj;
    PyObject *inst_dict;
    PyBindGenWrapperFlags flags:8;
} PyA;


extern PyTypeObject PyA_Type;

class PyA__PythonHelper : public A
{
public:
    PyObject *m_pyself;
    PyA__PythonHelper()
        : A(), m_pyself(NULL)
        {}


    void set_pyobj(PyObject *pyobj)
    {
        Py_XDECREF(m_pyself);
        Py_INCREF(pyobj);
        m_pyself = pyobj;
    }

    virtual ~PyA__PythonHelper()
    {
        Py_CLEAR(m_pyself);
    }


    virtual void virtualMethod1();

    virtual void virtualMethod2();
};



#include <map>
#include <string>
#include <typeinfo>
#if defined(__GNUC__) && __GNUC__ >= 3
# include <cxxabi.h>
#endif

#define PBG_TYPEMAP_DEBUG 0

namespace pybindgen {

class TypeMap
{
   std::map<std::string, PyTypeObject *> m_map;

public:

   TypeMap() {}

   void register_wrapper(const std::type_info &cpp_type_info, PyTypeObject *python_wrapper)
   {

#if PBG_TYPEMAP_DEBUG
   std::cerr << "register_wrapper(this=" << this << ", type_name=" << cpp_type_info.name()
             << ", python_wrapper=" << python_wrapper->tp_name << ")" << std::endl;
#endif

       m_map[std::string(cpp_type_info.name())] = python_wrapper;
   }



   PyTypeObject * lookup_wrapper(const std::type_info &cpp_type_info, PyTypeObject *fallback_wrapper)
   {

#if PBG_TYPEMAP_DEBUG
   std::cerr << "lookup_wrapper(this=" << this << ", type_name=" << cpp_type_info.name() << ")" << std::endl;
#endif

       PyTypeObject *python_wrapper = m_map[cpp_type_info.name()];
       if (python_wrapper)
           return python_wrapper;
       else {
#if defined(__GNUC__) && __GNUC__ >= 3

           // Get closest (in the single inheritance tree provided by cxxabi.h)
           // registered python wrapper.
           const abi::__si_class_type_info *_typeinfo =
               dynamic_cast<const abi::__si_class_type_info*> (&cpp_type_info);
#if PBG_TYPEMAP_DEBUG
          std::cerr << "  -> looking at C++ type " << _typeinfo->name() << std::endl;
#endif
           while (_typeinfo && (python_wrapper = m_map[std::string(_typeinfo->name())]) == 0) {
               _typeinfo = dynamic_cast<const abi::__si_class_type_info*> (_typeinfo->__base_type);
#if PBG_TYPEMAP_DEBUG
               std::cerr << "  -> looking at C++ type " << _typeinfo->name() << std::endl;
#endif
           }

#if PBG_TYPEMAP_DEBUG
          if (python_wrapper) {
              std::cerr << "  -> found match " << std::endl;
          } else {
              std::cerr << "  -> return fallback wrapper" << std::endl;
          }
#endif

           return python_wrapper? python_wrapper : fallback_wrapper;

#else // non gcc 3+ compilers can only match against explicitly registered classes, not hidden subclasses
           return fallback_wrapper;
#endif
       }
   }
};

}


extern pybindgen::TypeMap PyA__typeid_map;


typedef struct {
    PyObject_HEAD
    B *obj;
    PyObject *inst_dict;
    PyBindGenWrapperFlags flags:8;
} PyB;


extern PyTypeObject PyB_Type;

static PyMethodDef byhandtest_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */



pybindgen::TypeMap PyA__typeid_map;


void
PyA__PythonHelper::virtualMethod1()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    A *self_obj_before;
    PyObject *py_retval;

    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "virtualMethod1"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyA* >(m_pyself)->obj;
    reinterpret_cast< PyA* >(m_pyself)->obj = (A*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "virtualMethod1", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyA__PythonHelper::virtualMethod2()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    A *self_obj_before;
    PyObject *py_retval;

    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "virtualMethod2"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        A::virtualMethod2();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyA* >(m_pyself)->obj;
    reinterpret_cast< PyA* >(m_pyself)->obj = (A*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "virtualMethod2", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyA* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

static int
_wrap_PyA__tp_init(PyA *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (self->ob_type != &PyA_Type)
    {
        self->obj = new PyA__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyA__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'A' cannot be constructed");
        return -1;
    }
    return 0;
}


PyObject *
_wrap_PyA_virtualMethod1(PyA *self)
{
    PyObject *py_retval;

    self->obj->virtualMethod1();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyA_virtualMethod2(PyA *self)
{
    PyObject *py_retval;
    PyA__PythonHelper *helper_class = dynamic_cast<PyA__PythonHelper*> (self->obj);

    (helper_class == NULL)? (self->obj->virtualMethod2()) : (self->obj->A::virtualMethod2());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyA_methods[] = {
    {(char *) "virtualMethod1", (PyCFunction) _wrap_PyA_virtualMethod1, METH_NOARGS, NULL },
    {(char *) "virtualMethod2", (PyCFunction) _wrap_PyA_virtualMethod2, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyA__tp_clear(PyA *self)
{
    Py_CLEAR(self->inst_dict);
        A *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyA__tp_traverse(PyA *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);

    if (self->obj && typeid(*self->obj).name() == typeid(PyA__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyA__tp_dealloc(PyA *self)
{
    PyA__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyA__tp_richcompare (PyA *PYBINDGEN_UNUSED(self), PyA *other, int opid)
{

    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyA_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyA_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "byhandtest.A",            /* tp_name */
    sizeof(PyA),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyA__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyA__tp_traverse,     /* tp_traverse */
    (inquiry)PyA__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyA__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyA_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyA, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyA__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PyB__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'B' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}

static PyMethodDef PyB_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
PyB__tp_clear(PyB *self)
{
    Py_CLEAR(self->inst_dict);
        B *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyB__tp_traverse(PyB *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);

    return 0;
}


static void
_wrap_PyB__tp_dealloc(PyB *self)
{
    PyB__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyB__tp_richcompare (PyB *PYBINDGEN_UNUSED(self), PyB *other, int opid)
{

    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyB_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyB_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "byhandtest.B",            /* tp_name */
    sizeof(PyB),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyB__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyB__tp_traverse,     /* tp_traverse */
    (inquiry)PyB__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyB__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyB_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyB, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyB__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyMODINIT_FUNC
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif
initbyhandtest(void)
{
    PyObject *m;
    m = Py_InitModule3((char *) "byhandtest", byhandtest_functions, NULL);
    if (m == NULL) {
        return;
    }
    PyModule_AddObject(m, (char *) "_PyA__typeid_map", PyCObject_FromVoidPtr(&PyA__typeid_map, NULL));
    PyA__typeid_map.register_wrapper(typeid(A), &PyA_Type);
    /* Register the 'A' class */
    if (PyType_Ready(&PyA_Type)) {
        return;
    }
    PyModule_AddObject(m, (char *) "A", (PyObject *) &PyA_Type);
    PyA__typeid_map.register_wrapper(typeid(B), &PyB_Type);
    /* Register the 'B' class */
    PyB_Type.tp_base = &PyA_Type;
    if (PyType_Ready(&PyB_Type)) {
        return;
    }
    PyModule_AddObject(m, (char *) "B", (PyObject *) &PyB_Type);
}
