#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;




///Usar la libreria ctime para esta clase
class fecha
{
private:
    int dia, mes, anio;

public:
    ///gets
    int get_dia(){return dia;}
    int get_mes(){return mes;}
    int get_anio(){return anio;}


    ///sets
    void set_dia(int a)
    {
        dia=a;
        return;
    }
    void set_mes(int a)
    {
        mes=a;
        return;
    }
    void set_anio(int a)
    {
        anio=a;
        return;
    }

    ///funciones
    void cargar()
    {
        cout<<"Fecha: "<<endl;
        cout<<"Día: ";
        cin>>dia;
        cout<<"Mes: ";
        cin>>mes;
        cout<<"Año: ";
        cin>>anio;
    }
    void mostrar()
    {
        cout<<"Fecha : ";
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    bool validar_fecha();
};


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

//////////////////////////////////


class Medicion
{
    private:
    int cod_ciu;
    float visibilidad, temperatura;
    fecha medicion;
    public:
        ///gets
        int get_cod_ciu(){return cod_ciu;}
        float get_visibilidad(){return visibilidad;}
        float get_temperatura(){return temperatura;}
        fecha get_fecha(){return medicion;}

        ///sets
        void set_ent1(int a){cod_ciu=a;}
        void set_visibilidad(float a){visibilidad=a;}
        void set_temperatura(float a){temperatura=a;}
        void set_fecha(int dia, int mes, int anio)
        {
            medicion.set_anio(anio);
            medicion.set_mes(mes);
            medicion.set_dia(dia);
        }


        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

bool Medicion::leer(int pos)
{
    FILE *p;
    p=fopen("Mediciones.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Medicion), 0);
    bool leyo= fread(this, sizeof(Medicion), 1, p);
    fclose(p);
    return leyo;
}

class Ciudad
{
    private:
    int cod_ciudad, cod_prov;
    char nombre[30];

    public:
        ///gets
        int get_cod_ciudad(){return cod_ciudad;}
        int get_cod_prov(){return cod_prov;}
        char *get_nombre(){return nombre;}

        ///sets
        void set_cod_ciudad(int a){cod_ciudad=a;}
        void set_cod_prov(int a){cod_prov=a;}
        void set_nombre(const char *a){strcpy(nombre, a);}


        ///funciones genericas
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};


bool Ciudad::leer(int pos)
{
    FILE *p;
    p=fopen("Ciudades.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Ciudad), 0);
    bool leyo= fread(this, sizeof(Ciudad), 1, p);
    fclose(p);
    return leyo;
}

int contarCiudades()
{
    FILE *p;
    p=fopen("Ciudades.dat", "rb");
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Ciudad);
}

int buscarCiudad(int cc)
{
    Ciudad obj;
    int pos=0;
    while(obj.leer(pos++))
    {
        if(obj.get_cod_ciudad()==cc)
        {
            return pos;
        }
    }
    return -1;
}


class Promedio
{
public:
    ///GETS
    int get_cod_ciudad(){return cod_ciu;}
    int get_cant(){return cant;}
    char *get_nombre(){return nombre;}
    float get_promedio(){return promedio;}
    float get_suma(){return suma;}

    ///SETS
    void set_cod_ciudad(int a){cod_ciu=a;}
    void set_cant(int a){cant=a;}
    void set_nombre(const char *a){strcpy(nombre, a);}
    void set_promedio(float a){promedio=a;}
    void set_suma(float a){suma=a;}

    ///OPERADORES
    bool operator==(int cc)
    {
        if(cod_ciu==cc)return true;
        return false;
    }

    void operator=(int cc){cod_ciu=cc;}
    void operator=(char* nm){strcpy(nombre, nm);}
    void operator+=(float a){suma+=a;}



    ///CONSTRUCTOR
    Promedio(int cantidad=0, int s=0)
    {
        cant=cantidad;
        suma=s;
    }


private:
    int cod_ciu;
    char *nombre;
    float promedio, suma;
    int cant;
};




class Registro
{
public:
    ///GETS
    int get_cod_ciudad(){return cod_ciu;}
    char *get_nombre(){return nombre;}
    float get_promedio(){return promedio;}

    ///SETS
    void set_cod_ciudad(int a){cod_ciu=a;}
    void set_nombre(const char *a){strcpy(nombre, a);}
    void set_promedio(float a){promedio=a;}

    ///OPERADORES
    bool operator==(int cc)
    {
        if(cod_ciu==cc)return true;
        return false;
    }

    void operator=(int cc){cod_ciu=cc;}
    void operator=(char* nm){strcpy(nombre, nm);}
    void operator=(float prom){promedio=prom;}

    ///METODOS
    bool guardar();

private:
    int cod_ciu;
    char *nombre;
    float promedio;
};


bool Registro::guardar()
{
    FILE *p;
    p=fopen("Promedios.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof(Promedio), 1, p);
    fclose(p);
    return escribio;
}


#include "Punto2.h"

///////////////////////////////////



void Punto1();
void calcularPromedio(Promedio* , int);
void copiarCiudades(Promedio* , int );
void sumarMediciones(Promedio* );
void generarRegistroPromedio(Promedio* , int);


int main()
{
    punto2();
    return 0;
}



void Punto1()
{
    Promedio* obj;

    int cant=contarCiudades();
    obj= new Promedio[cant];
    if(obj==NULL) return;
    copiarCiudades(obj, cant);
    sumarMediciones(obj);
    calcularPromedio(obj, cant);
    generarRegistroPromedio(obj, cant);
    delete(obj);

}


void copiarCiudades(Promedio* vec, int cant)
{
    Ciudad obj;
    for(int i=0; i<cant; i++)
    {
        obj.leer(i);
        vec[i]=obj.get_cod_ciudad();
        vec[i]=obj.get_nombre();
    }
    return;
}


void sumarMediciones(Promedio* vec)
{
    Medicion obj;
    int pos=0, Registro;
    while(obj.leer(pos++))
    {
        Registro=buscarCiudad(obj.get_cod_ciu());
        vec[Registro].set_cant(vec[Registro].get_cant()+1);
        vec[Registro]+=obj.get_visibilidad();
    }

}


void calcularPromedio(Promedio* vec, int cant)
{
    for(int i=0; i<cant; i++)
    {
        float prom=(float)vec[i].get_suma()/vec[i].get_cant();
        vec[i].set_promedio(prom);

    }
}

void generarRegistroPromedio(Promedio *vec, int cant)
{
    Registro obj;
    for(int i=0; i<cant; i++)
    {
        obj=vec[i].get_cod_ciudad();
        obj=vec[i].get_nombre();
        obj=vec[i].get_promedio();
        obj.guardar();
    }
}
