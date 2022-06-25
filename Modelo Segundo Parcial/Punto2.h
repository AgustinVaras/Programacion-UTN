#ifndef PUNTO2_H_INCLUDED
#define PUNTO2_H_INCLUDED


void punto2();
void Inicializar_Matriz(int *);
void gradosVisibilidad(int *);


void punto2()
{
    const int filas=6;
    int Mediciones[filas]
    Inicializar_Matriz(Mediciones, filas, columnas);
    gradosVisibilidad(Mediciones);
    for(int i=0; i<filas; i++)
    {


    }

}




void Inicializar_Matriz(int *matr[31], int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
            matr[i][j]=0;
    }
}


void gradosVisibilidad(int *vec)
{
    Medicion obj;
    int pos=0;
    while(obj.leer(pos++))
    {
        if(obj.get_fecha().get_mes()==5)
        {
            if(obj.get_visibilidad()>10000)
            {
                matr[5][obj.get_fecha().get_dia()-1]++;
            }

            if(obj.get_visibilidad()>4000 && obj.get_visibilidad()<=10000)
            {
                matr[4][obj.get_fecha().get_dia()-1]++;
            }

            if(obj.get_visibilidad()>1000 && obj.get_visibilidad()<=4000)
            {
                matr[3][obj.get_fecha().get_dia()-1]++;
            }

            if(obj.get_visibilidad()>500 && obj.get_visibilidad()<=1000)
            {
                matr[2][obj.get_fecha().get_dia()-1]++;
            }

            if(obj.get_visibilidad()>50 && obj.get_visibilidad()>=500)
            {
                matr[1][obj.get_fecha().get_dia()-1]++;
            }

            if(obj.get_visibilidad()<50)
            {
                matr[0][obj.get_fecha().get_dia()-1]++;
            }
        }

    }
}

#endif // PUNTO2_H_INCLUDED
