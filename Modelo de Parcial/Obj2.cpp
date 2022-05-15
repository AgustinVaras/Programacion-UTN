#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#include "Fecha.h"
#include "Obj2.h"

void obj2::set_fecha(fecha a)
    {
        f.set_anio(a.get_anio());
        f.set_mes(a.get_mes());
        f.set_dia(a.get_dia());
    }
