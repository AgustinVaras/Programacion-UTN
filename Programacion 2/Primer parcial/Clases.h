#ifndef OBJETOS_GENERICOS_H_INCLUDED
#define OBJETOS_GENERICOS_H_INCLUDED


///Usar la libreria ctime para esta clase
class fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Mostrar();
        void Cargar();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){if(m>=1 && m<=12) mes=m;}
        void setAnio(int a){anio=a;}
        ~fecha(){};
};

void fecha::Mostrar(){
    ///cout<<this<<endl;
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}

void fecha::Cargar(){
    int d;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}
//////////////////////////////////


class Equipo
{
    private:
    int codigoEquipo, provincia;
    char nombreEquipo[30];
    char directorTecnico[30];
    char division;
    bool estado;

    public:
        ///gets
        int get_codigoEquipo(){return codigoEquipo;}
        int get_provincia(){return provincia;}
        char *get_nombreEquipo(){return nombreEquipo;}
        char *get_directorTecnico(){return directorTecnico;}
        char get_division(){return division;}
        bool get_estado(){return estado;}

        ///sets
        void set_codigoEquipo(int a){codigoEquipo=a;}
        void set_provincia(int a){provincia=a;}
        void set_nombreEquipo(char *a){strcpy(nombreEquipo, a);}
        void set_directorTecnico(char *a){strcpy(directorTecnico, a);}
        void set_division(char a){division=a;}
        void set_estado(bool a){estado=a;}

        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};


bool Equipo::leer(int pos)
{
    FILE *P;
    P=fopen("Equipos.dat", "rb");
    if(P==NULL) return false;
    fseek(P, pos * sizeof(Equipo), 0);
    bool leyo=fread(this, sizeof(Equipo), 1, P);
    fclose(P);
    return leyo;
}


class jugador
{
    private:
    int codigoJugador, edad, numeroCamiseta, codigoEquipo;
    char nombre[30];
    bool estado;

    public:
        ///Constructor
        jugador(char* );

        ///gets
        int get_codigoJugador(){return codigoJugador;}
        int get_edad(){return edad;}
        int get_numeroCamiseta(){return numeroCamiseta;}
        int get_codigoEquipo(){return codigoEquipo;}
        char *get_nombre(){return nombre;}
        bool get_estado(){return estado;}

        ///sets
        void set_codigoJugador(int a){codigoJugador=a;}
        void set_edad(int a){edad=a;}
        void set_numeroCamiseta(int a){numeroCamiseta=a;}
        void set_codigoEquipo(int a){codigoEquipo=a;}
        void set_nombre(char *a){strcpy(nombre, a);}

        void set_estado(bool a){estado=a;}

        ///funciones genericas
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

jugador::jugador(char *nom="VACIO")
{
    strcpy(nombre, nom);
}

bool jugador::leer(int pos)
{
    FILE *P;
    P=fopen("Jugadores.dat", "rb");
    if(P==NULL) return false;
    fseek(P, pos*sizeof(jugador), 0);
    bool leyo=fread(this, sizeof(jugador), 1, P);
    fclose(P);
    return leyo;
}

class Partido
{
    private:
    int codigoPartido,codigoSede, codigoEquipo1, codigoEquipo2;
    fecha fechaPartido;
    bool estado;

    public:
        ///gets
        int get_codigoPartido(){return codigoPartido;}
        int get_codigoSede(){return codigoSede;}
        int get_codigoEquipo1(){return codigoEquipo1;}
        int get_codigoEquipo2(){return codigoEquipo2;}

        fecha get_fecha(){return fechaPartido;}
        int get_anio(){return fechaPartido.getAnio();}
        int get_mes(){return fechaPartido.getMes();}
        int get_dia(){return fechaPartido.getDia();}
        bool get_estado(){return estado;}

        ///sets
        void set_codigoPartido(int a){codigoPartido=a;}
        void set_codigoSede(int a){codigoSede=a;}
        void set_codigoEquipo1(int a){codigoEquipo1=a;}
        void set_codigoEquipo2(int a){codigoEquipo2=a;}

        void set_fecha(fecha a)
        {
            fechaPartido.setAnio(a.getAnio());
            fechaPartido.setMes(a.getMes());
            fechaPartido.setDia(a.getDia());
        }
        void set_estado(bool a){estado=a;}

        ///funciones genericas
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};



bool Partido::leer(int pos)
{
    FILE *P;
    P=fopen("Partidos.dat", "rb");
    if(P==NULL) return false;
    fseek(P, pos*sizeof(Partido), 0);
    bool leyo=fread(this, sizeof(Partido), 1, P);
    fclose(P);
    return leyo;
}

#endif // OBJETOS_GENERICOS_H_INCLUDED
