/*****************************************************************************/
/*Laboratoire 2                                                              */
/*Présenter à : Jérémy Bouchard                                              */
/*Réalisé par : Vincent Tremblay                                             */
/*              Jérome Blackburn Saucier                                     */
/*Code permanent : TREV11080000                                              */
/*                 BLAJ01019200                                              */
/*L'ensemble du travail utilise le code de base fournis par notre professeur */
/*Le laboratoire consiste a faire fonctionné un module c++ en python         */
/*****************************************************************************/



#include <Python.h>
#pragma comment(lib, "Strmiids.lib")
#include <stdio.h>
#include <conio.h>
#include <dshow.h>
#include <iostream>
#include "Controle.h"
#include <codecvt>

using namespace std;

Controle lec;

//PyObject* constructeur(PyObject* self, PyObject* args)
//{
//}

PyObject* lecteur(PyObject* self, PyObject* args)
{
       
        char selectionControle = NULL;
        const char* path = NULL;
        PyArg_ParseTuple(args, "s", &path);
        

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(path);
        LPCWSTR result = wide.c_str();
      
        PyObject* python_val = Py_BuildValue("i", 1);

        lec.hr = lec.pGraph->RenderFile(result, NULL);

        if (SUCCEEDED(lec.hr))
        {
            // Run the graph.
            lec.pControl->Run();
            lec.pControl->Pause();
            lec.m_state = ETAT_PAUSE;
        }

                //while (selectionControle != 'q' && selectionControle != 'Q') {
                //
                //    //selectionControle = _getch();
                //    switch (selectionControle) {
                //
                //    case 'A':
                //    case 'a':
                //        lec->AvanceRapide();
                //        break;
                //    case 'P':
                //    case 'p':
                //
                //        if (lec->GetEtat() == ETAT_ENCOURS)
                //        {
                //            lec->Pause();
                //        }
                //        else if (lec->GetEtat() == ETAT_PAUSE)
                //        {
                //            lec->Play();
                //        } 
                //        break;
                //    case 'R':
                //    case 'r':
                //        lec->RetourOrigine();
                //        break;
                //    default:
                //        break;
                //    }
                //}
                //lec->~Controle();
        return python_val;
    
}

PyObject* PlayVideo(PyObject* self,PyObject* arg)
{
    if (lec.GetEtat() == ETAT_ENCOURS)
    {
        lec.Pause();
    }
    else if (lec.GetEtat() == ETAT_PAUSE)
    {
        lec.Play();
    } 
    PyObject* python_val = Py_BuildValue("i", 1);
    return python_val;
}

PyObject* AvanceRapid(PyObject* self, PyObject* arg)
{
    lec.AvanceRapide();
    PyObject* python_val = Py_BuildValue("i", 1);
    return python_val;
}

PyObject* RetourDebut(PyObject* self, PyObject* arg)
{
    lec.RetourOrigine();
    PyObject* python_val = Py_BuildValue("i", 1);
    return python_val;
}

PyObject* Quit(PyObject* self, PyObject* arg)
{
    lec.~Controle();
    PyObject* python_val = Py_BuildValue("i", 1);
    return python_val;
}

 static PyMethodDef methods[] = {

     {"lecteur", (PyCFunction)lecteur, METH_VARARGS, "read a video"},
     {"PlayVideo", PlayVideo, METH_NOARGS, "Lance le video et l'arrete"},
     {"AvanceRapid", AvanceRapid, METH_NOARGS, "Video accélérer"},
     {"RetourDebut", RetourDebut, METH_NOARGS, "Video accélérer"},
     {"Quit", Quit, METH_NOARGS, "Video accélérer"},


 { NULL, NULL, 0, NULL }

 };

 static struct PyModuleDef Laboratoire2 = {
    
    PyModuleDef_HEAD_INIT, 
    "Laboratoire2",
    "Essais de laboratoire 2",
    -1,
    methods
 
 };

 PyMODINIT_FUNC PyInit_Laboratoire2()
 {
     return PyModule_Create(&Laboratoire2);
 }
   


