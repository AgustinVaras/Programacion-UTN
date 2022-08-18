#ifndef OBJ1_H_INCLUDED
#define OBJ1_H_INCLUDED

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
        void set_cad1(char *);
        void set_cad2(char *);
        void set_estado(bool a){estado=a;}

        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};

#endif // OBJ1_H_INCLUDED
