#ifndef PUNTO2_H_INCLUDED
#define PUNTO2_H_INCLUDED


void punto2();

void Inicializar_Matriz(int *);

void punto2()
{
    int Mediciones[5][31]={0};


}




void Inicializar_Matriz(int *matr[31], int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
            matr[i][j]=0;
    }
}

#endif // PUNTO2_H_INCLUDED
