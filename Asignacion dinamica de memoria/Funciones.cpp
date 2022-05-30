#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "Funciones.h"

void mostrarVector(float *v, int tam)
{
    system("cls");
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<endl;
        cout<<endl;
    }
}
