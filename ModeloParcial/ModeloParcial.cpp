#include <iostream>

using namespace std;
#include <cstring>
#include <iomanip>
#include "ModeloParcial.h"
#include "examen.h"








bool Examen2022(int );
int Contar_aprob(int );
int Contar_desaprob(int );




void ModeloParcial::punto1()
{
    Estudiante listado;
    int pos=0;
    cout<<"ESTUDIANTES QUE NO RINDIERON EXAMEN EN 2022"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    while(listado.LeerDeDisco(pos++))
    {
        if(Examen2022(listado.getLegajo())==false)
        {
            cout<<"Legajo: "<<listado.getLegajo()<<endl;
            cout<<listado.getNombres()<<" "<<listado.getApellidos()<<endl;
            cout<<endl;
        }
    }
    cout<<"---------------------------------------------------------"<<endl;
}


void ModeloParcial::punto2()
{
    Estudiante listado;
    cout<<left;
    cout<<setw(8)<<"Legajo";
    cout<<setw(16)<<"Nombres";
    cout<<setw(16)<<"Apellidos";
    cout<<setw(10)<<"CantAprob";
    cout<<setw(13)<<"CantDesaprob";
    cout<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;

    int pos=0;
    while(listado.LeerDeDisco(pos++))
    {
        int cantAprob=Contar_aprob(listado.getLegajo()), cantDesaprob=Contar_desaprob(listado.getLegajo());
        cout<<left;
        cout<<setw(8)<<listado.getLegajo();
        cout<<setw(16)<<listado.getNombres();
        cout<<setw(17)<<listado.getApellidos();
        cout<<setw(11)<<cantAprob;
        cout<<setw(13)<<cantDesaprob;
        cout<<endl;
    }
    cout<<"----------------------------------------------------------------------------"<<endl;
}





///FUNCIONES GLOBALES


bool Examen2022(int legajo)
{
    Examen busc;
    int pos=0;
    while(busc.LeerDeDisco(pos++))
    {
        if(busc.getLegajo()==legajo)
            if(busc.getFecha().getAnio()==2022)
            return true;
    }
    return false;
}

int Contar_aprob(int legajo)
{
    Examen busc;
    int pos=0, cant=0;
    while(busc.LeerDeDisco(pos++))
    {
        if(busc.getLegajo()==legajo)
            if(busc.getNota()>=6) cant++;
    }
    return cant;
}

int Contar_desaprob(int legajo)
{
    Examen busc;
    int pos=0, cant=0;
    while(busc.LeerDeDisco(pos++))
    {
        if(busc.getLegajo()==legajo)
            if(busc.getNota()<6) cant++;
    }
    return cant;
}
