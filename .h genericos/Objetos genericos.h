#ifndef OBJETOS_GENERICOS_H_INCLUDED
#define OBJETOS_GENERICOS_H_INCLUDED


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


class obj1
{
    private:
    int ent1, ent2, ent3;
    char cad1[30];
    char cad2[30];
    bool estado;

    public:
        ///gets
        int get_ent1(){return ent1;}
        int get_ent2(){return ent2;}
        int get_ent3(){return ent3;}
        char *get_cad1(){return cad1;}
        char *get_cad2(){return cad2;}
        bool get_estado(){return estado;}

        ///sets
        void set_ent1(int a){ent1=a;}
        void set_ent2(int a){ent2=a;}
        void set_ent3(int a){ent3=a;}
        void set_cad1(char *a){strcpy(cad1, a);}
        void set_cad2(char *a){strcpy(cad2, a);}
        void set_estado(bool a){estado=a;}

        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

class obj2
{
    private:
    int ent1, ent2:
    char cad1[30];
    char cad2[30];
    fecha f;
    bool estado;

    public:
        ///gets
        int get_ent1(){return ent1;}
        int get_ent2(){return ent2;}
        char *get_cad1(){return cad1;}
        char *get_cad2(){return cad2;}
        fecha get_fecha(){return f;}
        int get_anio(){return f.get_anio();}
        int get_mes(){return f.get_mes();}
        int get_dia(){return f.get_dia();}
        bool get_estado(){return estado;}

        ///sets
        void set_ent1(int a){ent1=a;}
        void set_ent2(int a){ent2=a;}
        void set_cad1(char *a){strcpy(cad1, a);}
        void set_cad2(char *a){strcpy(cad2, a);}
        void set_fecha(fecha a)
        {
            f.set_anio(a.get_anio());
            f.set_mes(a.get_mes());
            f.set_dia(a.get_dia());
        }
        void set_estado(bool a){estado=a;}

        ///funciones genericas
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

#endif // OBJETOS_GENERICOS_H_INCLUDED
