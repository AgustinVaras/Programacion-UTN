#include <ctime>
#include <iostream>

using namespace std;

#include "Fecha.h"

///SETS
    void fecha::set_dia(int a)
    {
        dia=a;
        return;
    }
    void fecha::set_mes(int a)
    {
        mes=a;
        return;
    }
    void fecha::set_anio(int a)
    {
        anio=a;
        return;
    }


///GETS
    int fecha::get_dia(){return dia;}
    int fecha::get_mes(){return mes;}
    int fecha::get_anio(){return anio;}


///Funciones basicas
void fecha::cargar()
{
    cout<<"Fecha: "<<endl;
    cout<<"Día: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Año: ";
    cin>>anio;
}

void fecha::mostrar()
{
    cout<<"Fecha : ";
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

///Validar Fecha
bool fecha::validar_fecha()
{

  time_t tiempo;
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  if(dia>31 || dia<1)
  {
      cout<<"El día no puede ser un número mayor a 31 ni menor a 1"<<endl;
      return false;
  }else
  {
      if(mes>12 || mes<1)
      {
          cout<<"El mes no puede ser un número menor a 1 ni mayor que 12"<<endl;
          return false;
      }else
      {
          if(anio<1)
          {
              cout<<"El año no puede ser un número menor a 1"<<endl;
              return false;
          }
      }
  }

  if(anio<tmPtr->tm_year+1900)
  {
      return true;
  }else
  {
      if(anio==tmPtr->tm_year+1900)
      {
          if(mes<tmPtr->tm_mon)
          {
              return true;
          }else
          {
              if(mes==tmPtr->tm_mon)
              {
                  if(dia<=tmPtr->tm_mday)
                  {
                      return true;
                  }else
                  {
                      cout<<"LA FECHA INGRESADA NO PUEDE SER MAYOR A LA FECHA ACTUAL"<<endl;
                      return false;
                  }
              }else
              {
                cout<<"LA FECHA INGRESADA NO PUEDE SER MAYOR A LA FECHA ACTUAL"<<endl;
                return false;
              }
          }
      }
        cout<<"LA FECHA INGRESADA NO PUEDE SER MAYOR A LA FECHA ACTUAL"<<endl;
        return false;
  }

}
