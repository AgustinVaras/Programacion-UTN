#ifndef MENUS_GENERICOS_H_INCLUDED
#define MENUS_GENERICOS_H_INCLUDED

void menu_()
{
    int opc;
    bool cond=true;
    while(cond==true)
    {
        system("cls");
        cout<<"---------------MEN� -------------"<<endl;
        cout<<"1) "<<endl;
        cout<<"2) "<<endl;
        cout<<"3) "<<endl;
        cout<<"4) "<<endl;
        cout<<"5) "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MEN� PRINCI�L"<<endl;
        cout<<"SELECCIONE UNA OPCI�N: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            system("pause");
            break;

        case 2:
            system("pause");
            break;

        case 3:
            system("pause");
            break;

        case 4:
            system("pause");
            break;

        case 5:
            system("pause");
            break;

        case 0:
            system("cls");
            cout<<"Volviendo al men� principal"<<endl;
            cond=false;
            break;

        default:
            cout<<"Opci�n incorrecta, por favor seleccione una opci�n valida"<<endl;
            system("pause");
            break;
        }
    }
    return;
}


#endif // MENUS_GENERICOS_H_INCLUDED
