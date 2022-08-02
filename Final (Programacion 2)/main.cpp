#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

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


class Tecnicos
{
private:

    int DNI, localidad, edad, genero, puesto;
    float sueldo;
    char nombre[50];
    char apellido[50];
    fecha F;

public:
    int get_DNI(){return DNI;}
    int get_puesto(){return puesto;}
    char* get_nombre(){return nombre;}
    char* get_apellido(){return apellido;}

    void set_nombre(char* a){strcpy(nombre, a);}
    void set_DNI(int a){DNI=a;}

    bool leer(int pos);

    bool operator==(int dni_obra)
    {
        if(DNI==dni_obra) return true;
        return false;
    }
};


bool Tecnicos::leer(int pos)
{
    FILE* p;
    p=fopen("Tecnicos.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Tecnicos), 0);
    bool leyo=fread(this, sizeof(Tecnicos), 1, p);
    fclose(p);
    return leyo;
}



class Tecnicos_obras
{
private:
    int num, DNI, tipo, dias;
    fecha f;

public:
    int get_DNI(){return DNI;}

    bool leer(int pos);
};

bool Tecnicos_obras::leer(int pos)
{
    FILE* p;
    p=fopen("Tecnicos_obras.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Tecnicos_obras), 0);
    bool leyo=fread(this, sizeof(Tecnicos_obras), 1, p);
    fclose(p);
    return leyo;
}


class tec4
{
private:
    int DNI;
    char nombre[50];
    char apellido[50];
    int cant;

public:
    void set_DNI(int a){DNI=a;}
    void set_cant(int a){cant=a;}
    void set_nombre(char* a){strcpy(nombre, a);}
    void set_apellido(char* a){strcpy(apellido, a);}

    int get_cant(){return cant;}
    tec4(int a=0)
    {
        cant=a;
    }

    bool guardar();

    void operator++(int a=1)
    {
        cant++;
    }

};

bool tec4::guardar()
{
    FILE *p;
    p=fopen("tec4.dat", "ab");
    if(p==NULL) return false;
    bool escribio= fwrite(this, sizeof(tec4), 1, p);
    fclose(p);
    return escribio;
}



///declaracion de funciones para el punto 1 - a)
void punto1();
int contarTecnicos_Obras();
void cargarTecnicos_Obras(Tecnicos_obras*, int cant);

///declacaracion de funciones para punto 1 - b)
void punto1_b();



int main()
{
    setlocale(LC_ALL, "Spanish");
    int opc;
    bool cond=true;
    while(cond==true)
    {
        system("cls");
        cout<<"---------------MENÚ -------------"<<endl;
        cout<<"1)PUNTO 1-a)"<<endl;
        cout<<"2)PUNTO 1-b) "<<endl;
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
            punto1_b();
            system("pause");
            break;
        case 0:
            system("cls");
            cout<<"Volviendo al menú principal"<<endl;
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


int contarTecnicos_Obras()
{
    FILE* p;
    p=fopen("Tecnicos_obras.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, 2);
    int cant=ftell(p);
    fclose(p);
    return cant/sizeof(Tecnicos_obras);
}


void cargarTecnicos_Obras(Tecnicos_obras* vec, int cant)
{
    vec=new Tecnicos_obras[cant];

    for(int i=0; i<cant; i++)
    {
        vec[i].leer(i);
    }
    delete(vec);
    return;
}

void punto1()
{
    system("cls");
    Tecnicos tec;
    Tecnicos_obras* obr;
    tec4 obj;

    obj++;
    cout<<obj.get_cant();


    int pos=0, cant=contarTecnicos_Obras();
    if(cant==-1)
    {
        cout<<"Imposible cargar registro de Obras"<<endl;
        return;
    }
    cargarTecnicos_Obras(obr, cant);

    while(tec.leer(pos++))
    {
        obj.set_nombre(tec.get_nombre());
        obj.set_apellido(tec.get_apellido());

        for(int i=0; i<cant; i++)
        {
            if(tec.get_DNI()==obr[i].get_DNI())
            {
                obj++;
            }
        }
        obj.guardar();
    }

}


void punto1_b()
{
    system("cls");
    int puestos[10]={0};
    Tecnicos obj;
    int pos=0;
    while(obj.leer(pos++))
    {
        puestos[obj.get_puesto()-1]++;
    }

    int Max=puestos[0];
    int posMax=0;
    for(int i=0; i<10; i++)
    {
        if(puestos[i]>Max)
        {
            Max=puestos[i];
            posMax=i;
        }
    }

    cout<<"El puesto con más técnicos es el número: "<<posMax+1<<endl;
}

void punto2()
{
    Tecnicos obj;
    Tecnicos_obras prueba;

    if(prueba.leer(1)==false) return;

    cout<<"DNI del tecnico de la obra: "<<prueba.get_DNI()<<endl;
    cout<<"Ingrese DNI a comparar: ";
    int DNI;
    cin>>DNI;

    obj.set_DNI(DNI);
    if(obj==prueba.get_DNI()){
        cout<<"Son iguales"<<endl;
    }else
    {
        cout<<"Son distintos"<<endl;
    }

}
