#ifndef OBJ2_H_INCLUDED
#define OBJ2_H_INCLUDED

class obj2
{
    private:
    int ent1, ent2;
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
        void set_fecha(fecha );
        void set_estado(bool a){estado=a;}

        ///funciones genericas
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

#endif // OBJ2_H_INCLUDED
