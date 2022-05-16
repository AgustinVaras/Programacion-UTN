#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#include "Clases.h"


class PartidosLocales
{
    private:
    int cod_contrario, codigoSede;
    fecha fechaPartido;

    public:
        void set_cod_contrario(int a){cod_contrario=a;}
        void set_codigoSede(int a){codigoSede=a;}
        void set_fecha(fecha a)
        {
            fechaPartido.setAnio(a.getAnio());
            fechaPartido.setMes(a.getMes());
            fechaPartido.setDia(a.getDia());
        }


        bool guardar();
};

bool PartidosLocales::guardar()
{
    FILE *P;
    P= fopen("Partidos Locales.dat", "ab");
    if(P==NULL) return false;
    bool guardo=fwrite(this, sizeof(PartidosLocales), 1, P);
    fclose(P);
    return guardo;
}

int buscar_cod_Equipo(char *);


void punto1();
void punto2();



int main()
{
    setlocale(LC_ALL, "Spanish");
    int opc;
    bool cond=true;
    while(cond==true)
    {
        system("cls");
        cout<<"---------------MENÚ -------------"<<endl;
        cout<<"1)PUNTO 1 "<<endl;
        cout<<"2)PUNTO 2 "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENÚ PRINCIÁL"<<endl;
        cout<<"SELECCIONE UNA OPCIÓN: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            punto1();
            system("pause");
            break;

        case 2:
            punto2();
            system("pause");
            break;

        case 0:
            system("cls");
            cout<<"Cerrando el programa"<<endl;
            cond=false;
            break;

        default:
            cout<<"Opción incorrecta, por favor seleccione una opción valida"<<endl;
            system("pause");
            break;
        }
    }
    return 0;
}




void punto1()
{
    system("cls");
    char nombreEquipo[30];
    Partido obj;

    cout<<"Ingrese nombre de equipo: ";
    cin.ignore();
    cin.getline(nombreEquipo, 30);
    int cod=buscar_cod_Equipo(nombreEquipo);
    if(cod==-1)
    {
        cout<<"Ese nombre de equipo no existe en el registro"<<endl;
        return;
    }

    PartidosLocales aux;
    int pos=0;
    while(obj.leer(pos++))
    {
        if(obj.get_codigoEquipo1()==cod)
        {
            aux.set_cod_contrario(obj.get_codigoEquipo2());
            aux.set_codigoSede(obj.get_codigoSede());
            aux.set_fecha(obj.get_fecha());
            if(aux.guardar()==false)
            {
                cout<<"ERROR AL GUARDAR"<<endl;
                cout<<endl;
            }
        }
    }
    system("pause");
    return;
}

int buscar_cod_Equipo(char *nombre)
{
    int pos=0;
    Equipo obj;
    if(obj.leer(pos++))
    {
        if(strcmp(obj.get_nombreEquipo(),nombre)==0) return obj.get_codigoEquipo();
    }
    return -1;
}


void punto2()
{
    system("cls");
    jugador obj;
    int camisetas[35]={0};
    int pos=0;
    while(obj.leer(pos++))
    {
        camisetas[obj.get_numeroCamiseta()-1]++;
    }
    int menor, posMenor;
    for(int i=0; i<35; i++)
    {
        if(i==0)
        {
            menor=camisetas[i];
            posMenor=i+1;
        }else
        {
            if(camisetas[i]<menor)
            {
                menor=camisetas[i];
                posMenor=i+1;
            }
        }
    }
    cout<<"La camiseta con menos jugadores es la numero "<<posMenor<<endl;
}

