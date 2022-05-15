#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

///Usar la libreria ctime para esta clase
class fecha
{
private:
    int dia, mes, anio;

public:
    ///gets
    int get_dia();
    int get_mes();
    int get_anio();


    ///sets
    void set_dia(int );
    void set_mes(int );
    void set_anio(int );


    ///funciones
    void cargar();
    void mostrar();

    bool validar_fecha();
};

#endif // FECHA_H_INCLUDED
