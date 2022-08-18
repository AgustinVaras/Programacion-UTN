#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


#include "Funciones.h"


int main()
{
    float *articulos;
    int articulo, cantArticulos=0;
    float importe;
    cout<<"Cantidad de articulos: ";
    cin>>cantArticulos;
    ///COMO SE LA CANTIDAD PUEDO PEDIR MEMORIA PARA CONSTRUIR EL VECTOR
    articulos=new float[cantArticulos]; ///Pedir memoria para el vector
    if(articulos==NULL) return -1;
    delete articulos;
    cout<<"ARTICULO: ";
    cin>>articulo;

    while(articulo!=0)
    {
        cout<<"IMPORTE: ";
        cin>>importe;
        articulos[articulo-1]+=importe;
        cout<<endl;
        cout<<"ARTICULO: ";
        cin>>articulo;
    }
    mostrarVector(articulos, cantArticulos);
    cout<<endl;
    system("pause");
    return 0;
}
