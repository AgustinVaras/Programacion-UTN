#ifndef FUNCIONES_GENERICAS_H_INCLUDED
#define FUNCIONES_GENERICAS_H_INCLUDED

int contar_registros()
{
    FILE *p;
    p=fopen("Archivo.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof();
}

void Inicializar_Matriz(int *matr[31], int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
            matr[i][j]=0;
    }
}

int buscar_registro(int id)
{
    obj1 a;
    int pos=0;
    while(a.leer(pos)==true)
    {
        if(a.get_ID()==id)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}


void cargar_registro()
{
    obj1 a;
    if(a.cargar(contar_registro()+1)==true)
    {
        cout<<"Cargado con exito"<<endl;
        if(a.guardar()==true)
        {
            cout<<"Guardado con exito"<<endl;
            return;
        }else
        {
            cout<<"Error al guardar"<<endl;
            return;
        }
    }
}

void listar()
{
    system("cls");
    obj1 a;
    int pos=0;
    while(a.leer(pos)==true)
    {
        a.mostrar();
        cout<<endl;
        pos++;
    }
}

#endif // FUNCIONES_GENERICAS_H_INCLUDED
