///Ejercicio: Parcial 2 de Programación II
///Autor:DEK
///Fecha:13/06/2022
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
private:
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Obra{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    float superficie;
    int estadoEjecucion;
    bool activo;
public:
    void Cargar(){
        cargarCadena(codigoObra,4);
        cargarCadena(direccion,29);
        cin>>provincia;
        cin>>superficie;
        cin>>estadoEjecucion;
        activo=true;
    }

    void Mostrar(){
        cout<<codigoObra<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
        cout<<superficie<<endl;
        cout<<estadoEjecucion<<endl;
    }

    const char* getCodigoObra(){return codigoObra;}
    const char* getDireccion(){return direccion;}
    int getProvincia(){return provincia;}
    int getEstadoEjecucion(){return estadoEjecucion;}
    float getSuperficie(){return superficie;}
    bool getActivo(){return activo;}

    void setCodigoObra(const char *co){strcpy(codigoObra, co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}
    void setEstadoEjecucion(int e){estadoEjecucion=e;}
    void setSuperficie(float s){superficie=s;}
    void setActivo(bool a){activo=a;}

    bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("obras.dat", "rb");
        if(p==NULL) return false;
        fseek(p, sizeof(Obra)*pos,0);
        bool leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("obras.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }
};

class Material{
private:
    int codigoMaterial;
    char nombre[30];
    char marca[30];
    int tipo;
    float pu;
    bool activo;
public:
    void Cargar(){
        cin>>codigoMaterial;
        cargarCadena(nombre,29);
        cargarCadena(marca,29);
        cin>>tipo;
        cin>>pu;
        activo=true;
    }
    void Mostrar(){
        cout<<codigoMaterial<<endl;
        cout<<nombre<<endl;
        cout<<marca<<endl;
        cout<<tipo<<endl;
        cout<<pu<<endl;
    }
    int getCodigoMaterial(){return codigoMaterial;}
    int getTipo(){return tipo;}
    const char *getNombre(){return nombre;}
    const char *getMarca(){return marca;}
    float getPU(){return pu;}
    bool getActivo(){return activo;}

    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setTipo(int t){tipo=t;}
    void setNombre(const char *m){strcpy(nombre,m);}
    void setMarca(const char *m){strcpy(marca,m);}
    void setPU(float p){pu=p;}
    void setActivo(bool a){activo=a;}

    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("materiales.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("materiales.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

    bool operator>(float precio)
    {
        if(pu > precio) return true;
        return false;
    }
};

class Compra{
private:
    int numeroCompra, numeroProveedor, codigoMaterial;
    char codigoObra[5];
    int cantidad;
    float importe;
    Fecha fechaCompra;
    bool activo;
public:
    void Cargar(){
        cin>>numeroCompra;
        cin>>numeroProveedor;
        cin>>codigoMaterial;
        cargarCadena(codigoObra,4);
        cin>>cantidad;
        cin>>importe;
        fechaCompra.Cargar();
        activo=true;
    }

    void Mostrar(){
        cout<<numeroCompra<<endl;
        cout<<numeroProveedor<<endl;
        cout<<codigoMaterial<<endl;
        cout<<codigoObra<<endl;
        cout<<cantidad<<endl;
        cout<<importe<<endl;
        fechaCompra.Mostrar();
        cout<<endl;
    }
    int getNumeroCompra(){return numeroCompra;}
    int getNumeroproveedor(){return numeroProveedor;}
    int getCodigoMaterial(){return codigoMaterial;}
    int getCantidad(){return cantidad;}
    float getImporte(){return importe;}
    Fecha getFechaCompra(){return fechaCompra;}
    const char *getCodigoObra(){return codigoObra;}
    bool getActivo(){return activo;}

    void setNumeroCompra(int nc){numeroCompra=nc;}
    void setNumeroproveedor(int np){numeroProveedor=np;}
    void setCodigoMaterial(int cm){codigoMaterial=cm;}
    void setCantidad(int c){cantidad=c;}
    void setImporte(float i){importe=i;}
    void setFechaCompra(Fecha f){fechaCompra=f;}
    void setCodigoObra(const char *co){strcpy(codigoObra,co);}
    void setActivo(bool a){activo=a;}

    bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("compras.dat", "rb");
        if(p==NULL) return false;
        fseek(p, sizeof *this*pos,0);
        bool leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("compras.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

    operator ==(float precio)
    {
        if(importe==precio)return true;
        return false;
    }
};

class Proveedor{
private:
    int numeroProveedor;
    char nombre[30];
    char telefono[30];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void Cargar(){
        cin>>numeroProveedor;
        cargarCadena(nombre,29);
        cargarCadena(telefono,29);
        cargarCadena(direccion,29);
        cin>>provincia;
        activo=true;
    }
    void Mostrar(){
        cout<<numeroProveedor<<endl;
        cout<<nombre<<endl;
        cout<<telefono<<endl;
        cout<<direccion<<endl;
        cout<<provincia<<endl;
    }

    int getNumeroProveedor(){return numeroProveedor;}
    int getProvincia(){return provincia;}
    const char *getNombre(){return nombre;}
    const char *getTelefono(){return telefono;}
    const char *getDireccion(){return direccion;}
    bool getActivo(){return activo;}

    void setNumeroProveedor(int np){numeroProveedor=np;}
    void setProvincia(int np){provincia=np;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTelefono(const char *n){strcpy(telefono,n);}
    void setDireccion(const char *n){strcpy(direccion,n);}
    void setActivo(bool a){activo=a;}


    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("proveedores.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof *this*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("proveedores.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }
};

class Registro
{
    private:
    int codigoMaterial, tipo, cant;

    public:
        ///gets
        int get_codigoMaterial(){return codigoMaterial;}
        int get_tipo(){return tipo;}
        int get_cant(){return cant;}

        ///sets
        void set_codigoMaterial(int a){codigoMaterial=a;}
        void set_tipo(int a){tipo=a;}
        void set_cant(int a){cant=a;}


        ///Constructor
        Registro(int cm=0, int tp=0, int cnt=0)
        {
            codigoMaterial=cm;
            tipo=tp;
            cant=cnt;
        }


        ///OPERADORES
        void operator=(int cm){codigoMaterial=cm;}

        ///Metodos
        bool cargar();
        void mostrar();
        bool guardar();
        bool leer(int pos);
};


bool Registro::guardar()
{
    FILE *p;
    p=fopen("Punto1.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof(Registro), 1, p);
    fclose(p);
    return escribio;
}

bool Registro::leer(int pos)
{
    FILE *p;
    p=fopen("Punto1.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Registro), 0);
    bool leyo=fread(this, sizeof(Registro),1, p);
    fclose(p);
    return leyo;
}

void Registro::mostrar()
{
    cout<<"Codigo Material: "<<codigoMaterial<<endl;
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Cantidad: "<<cant<<endl;
}

///FUNCIONES PUNTO 1
void punto1();
int contarMateriales();
int buscarMaterial(int cm);
void copiarMateriales(Registro* , int);
void acumularCompras(Registro* );
void generarRegistro(Registro* , int);
void listarRegistro()
{
    int pos=0;
    Registro obj;
    while(obj.leer(pos++))
    {
        obj.mostrar();
        cout<<endl;
    }
}
///////////////////////////////////////////

///FUNCIONES PUNTO 2
void punto2();
void obrasXprov(int* );
int sacarMax(int *);
void listarObras()
{
            system("cls");
            Obra obj;
            int pos=0;
            while(obj.leerDeDisco(pos++))
            {
                obj.Mostrar();
                cout<<endl;
            }
}

///FUNCIONES PUNTO 3
void punto3();
void cargarMateriales(Material* , int);
void listarMateriales(Material*, int, float);

///void punto4
void punto4();

int main(){
    setlocale(LC_ALL, "spanish");
    int opc;
    bool cond=true;
    while(cond==true)
    {
        system("cls");
        cout<<"---------------MENÚ -------------"<<endl;
        cout<<"1) PUNTO 1"<<endl;
        cout<<"2) PUNTO 2"<<endl;
        cout<<"3) PUNTO 3"<<endl;
        cout<<"4) PUNTO 4"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"0) CERRAR PROGRAMA"<<endl;
        cout<<"SELECCIONE UNA OPCIÓN: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            punto1();
            system("pause");
            listarRegistro();
            system("pause");
            break;

        case 2:
            punto2();
            system("pause");
            break;

        case 3:
            punto3();
            system("pause");
            break;

        case 4:
            punto4();
            system("pause");
            break;

        case 0:
            system("cls");
            cout<<"CERRANDO PROGRAMA"<<endl;
            cond=false;
            break;

        default:
            cout<<"Opción incorrecta, por favor seleccione una opción valida"<<endl;
            system("pause");
            break;
        }
    }
	system("pause");
	return 0;
}


int buscarMaterial(int cm)
{
    Material obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getCodigoMaterial()==cm) return pos;
    }
    return-1;
}


int contarMateriales()
{
    FILE *p;
    p=fopen("materiales.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0 , 2);
    int tam=ftell(p);
    return tam/sizeof(Material);
}


void punto1()
{
    system("cls");
    cout<<"Generando Registro"<<endl;
    Registro *vec;
    int cant;
    cant=contarMateriales();
    if(cant==-1)
    {
        cout<<"NO EXISTEN REGISTROS"<<endl;
        return;
    }
    cout<<"Cantidad de registros: "<<cant<<endl;
    system("pause");
    vec=new Registro[cant];
    if(vec==NULL) return;

    copiarMateriales(vec, cant);
    acumularCompras(vec);
    generarRegistro(vec, cant);

    delete(vec);
    cout<<"REGISTRO GENERADO"<<endl;
}


void copiarMateriales(Registro* vec, int cant)
{
    Material obj;
    for(int i=0; i<cant; i++)
    {
        obj.leerDeDisco(i);
        vec[i]=obj.getCodigoMaterial();
        vec[i].set_tipo(obj.getTipo());
    }

}

void acumularCompras(Registro* vec)
{
    Compra obj;
    int pos=0, reg;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getFechaCompra().getAnio()==2022)
        {
            reg=buscarMaterial(obj.getCodigoMaterial());
            vec[reg].set_cant(vec[reg].get_cant()+1);
        }
    }
}

void generarRegistro(Registro* vec, int cant)
{
    for(int i=0; i<cant; i++)
    {
        if(vec[i].guardar()==false)
        {
            cout<<"ERROR AL GUARDAR REGISTRO "<<i<<endl;
        }
    }
}



///PUNTO 2
void punto2()
{
    system("cls");
    int prov[24]={0};
    obrasXprov(prov);
    int provMax=sacarMax(prov);
    cout<<"LA PROVINCIA CON MÁS OBRAS ES LA NÚMERO: "<<provMax<<endl;

}

void obrasXprov(int* vec)
{
    Obra obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.getActivo()==true)
        {
            vec[obj.getProvincia()-1]++;
        }
    }
}

int sacarMax(int* prov)
{
    int posMax, Max;
    for(int i=0; i<24; i++)
    {
        if(i==0)
        {
            posMax=i;
            Max=prov[i];
        }else
        {
            if(prov[i]>Max)
            {
                posMax=i;
                Max=prov[i];
            }
        }
    }
    return posMax+1;
}



///PUNTO 3
void punto3()
{
    system("cls");

    Material *obj;
    int cant=contarMateriales();
    if(cant==-1)
    {
        cout<<"NO EXISTEN REGISTROS"<<endl;
        return;
    }
    obj= new Material[cant];
    if(obj==NULL) return;

    cargarMateriales(obj, cant);
    cout<<"INGRESE EL PRECIO: ";
    float precio;
    cin>>precio;

    listarMateriales(obj, cant, precio);


    delete(obj);
}


void cargarMateriales(Material* vec, int cant)
{
    for(int i=0; i<cant; i++)
    {
        vec[i].leerDeDisco(i);
    }
}

void listarMateriales(Material* vec, int cant, float precio)
{
    for(int i=0; i<cant; i++)
    {
        if(vec[i]>precio)
        {
            cout<<endl;
            vec[i].Mostrar();
        }
    }
}


///PUNTO 4

void punto4()
{
    system("cls");
    float importe;
    Compra obj;
    obj.setImporte(300);
    cout<<"IMPORTE DE COMPRA: "<<obj.getImporte()<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Ingrese un importe para comparar: ";
    cin>>importe;
    cout<<endl;
    if(obj==importe)
    {
        cout<<"SON IGUALES"<<endl;
    }else
    {
        cout<<"SON DISTINTOS"<<endl;
    }

}
