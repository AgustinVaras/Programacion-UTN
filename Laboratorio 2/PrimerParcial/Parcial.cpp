#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Viaje.h"
#include "Chofer.h"
#include "Parcial.h"
#include "FechaHora.h"


void calcular_promedio(float*, int* );
bool Mayor_cant_PrimerSemestre(int );
int ID_de_viajeMasExtenso();
bool Trabajo_Madrugada(int );


void Parcial::punto1()
{
    float promedios[4]= {0};
    int tipo[4]= {0};
    calcular_promedio(promedios, tipo);
    cout<<left;
    cout<<setw(18)<<"Tipo de viaje";
    cout<<setw(15)<<"Importe promedio";
    cout<<endl;
    cout<<left;
    cout<<setw(18)<<"Corto"<<"$"<<promedios[0]/tipo[0]<<endl;
    cout<<setw(18)<<"Mediano"<<"$"<<promedios[1]/tipo[1]<<endl;
    cout<<setw(18)<<"Largo"<<"$"<<promedios[2]/tipo[2]<<endl;
    cout<<setw(18)<<"Extenso"<<"$"<<promedios[3]/tipo[3]<<endl;
}


void Parcial::punto2()
{
    int cant=0;
    int pos=0;
    Chofer obj;
    while(obj.LeerDeDisco(pos++))
    {
        if(Mayor_cant_PrimerSemestre(obj.getID())==true)
            cant++;
    }
    cout<<"Hay "<<cant<<" choferes que realizaron mas viajes en el primer semestre de 2020"<<endl;
}


void Parcial::punto3()
{
    Chofer obj;
    FechaHora fecha;
    int Pos=buscar_chofer(ID_de_viajeMasExtenso());
    obj.LeerDeDisco(Pos);
    cout<<"Chofer con el viaje mas extenso: "<<endl;
    cout<<obj.getNombres()<<", ";
    cout<<obj.getApellidos()<<", ";
    cout<<obj.getPatente()<<", ";
    cout<<"Anios de antiguedad del vehiculo: "<<fecha.getAnio() - obj.getAnioPatentamiento()<<endl;
}





void Parcial::punto4()
{
    Chofer obj;
    int pos=0;
    cout<<"Choferes que trabajaron solo en el turno madrugada"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    while(obj.LeerDeDisco(pos++))
    {
        if(Trabajo_Madrugada(obj.getID())==true)
        {
            cout<<obj.getApellidos()<<", "<<obj.getNombres()<<endl;
        }
    }
    cout<<"------------------------------------------------------------------"<<endl;
}


///Funciones Globales
void calcular_promedio(float* prom, int* total)
{
    Viaje obj;
    int pos=0;
    while(obj.LeerDeDisco(pos++))
    {
        if(obj.getCancelado()!=true)
        {
            ///Cortos
            if(obj.getKms()>0 && obj.getKms()<10)
            {
                prom[0]+=obj.getImporte();
                total[0]++;
            }
            ///Medianos
            if(obj.getKms()>=10 && obj.getKms()<40)
            {
                prom[1]+=obj.getImporte();
                total[1]++;
            }
            ///Largos
            if(obj.getKms()>=40 && obj.getKms()<100)
            {
                prom[2]+=obj.getImporte();
                total[2]++;
            }
            ///Extensos
            if(obj.getKms()>=100)
            {
                prom[3]+=obj.getImporte();
                total[3]++;
            }
        }
    }
}


bool Mayor_cant_PrimerSemestre(int ID)
{
    Viaje obj;
    int pos=0, primerSemestre=0, segundoSemestre=0;
    while(obj.LeerDeDisco(pos++))
    {
        if(obj.getIDChofer()==ID)
        {
            if(obj.getFechaHora().getAnio()==2020 && obj.getCancelado()!=false)
            {
                if(obj.getFechaHora().getMes()>=1 && obj.getFechaHora().getMes()<=6)
                    primerSemestre++;

                if(obj.getFechaHora().getMes()>=7 && obj.getFechaHora().getMes()<=12)
                    segundoSemestre++;
            }
        }
    }
    if(primerSemestre>segundoSemestre) return true;

    return false;
}

int ID_de_viajeMasExtenso()
{
    Viaje obj;
    float Max=0;
    bool primero=false;
    int IDChofer, pos=0;
    while(obj.LeerDeDisco(pos++))
    {
        if(obj.getCancelado()==false)
        {
            if(primero==false)
            {
                Max=obj.getKms();
                IDChofer=obj.getIDChofer();
            }else
            {
                if(obj.getKms()>Max)
                {
                    Max=obj.getKms();
                    IDChofer=obj.getIDChofer();
                }
            }
        }
    }

    return IDChofer;
}

bool Trabajo_Madrugada(int ID)
{
    Viaje obj;
    int pos=0;
    while(obj.LeerDeDisco(pos++))
    {
        if(obj.getIDChofer()==ID && obj.getCancelado()==false)
            if(obj.getFechaHora().getHora()<1 || obj.getFechaHora().getHora()>6)
                return false;

    }
    return true;
}







