CREATE DATABASE Act1_3
GO

USE Act1_3
GO

Create Table CATEGORIAS(
    ID SMALLINT NOT NULL PRIMARY KEY,
    Nombre VARCHAR(40) NOT NULL CHECK(Nombre IN('Mueble Jardin', 'Mueble Banio', 'Mueble Cocina'))
)
GO

Create Table PRODUCTOS(
    Codigo SMALLINT NOT NULL PRIMARY KEY,
    Nombre VARCHAR(40) NOT NULL,
    Precio MONEY NOT NULL CHECK(Precio > 0),
    Precio_Mayorista MONEY NULL CHECK(Precio_Mayorista < Precio_Mayorista AND Precio_Mayorista > 0),
    Cant_Mayorista INT NULL,
    Dias_Const TINYINT NOT NULL CHECK(Dias_Const > 0),
    Categoria SMALLINT NOT NULL FOREIGN KEY REFERENCES CATEGORIAS(ID)
)
GO

Create Table CLIENTES(
    ID SMALLINT NOT NULL PRIMARY KEY,
    Apellidos VARCHAR(40) NOT NULL,
    Nombres VARCHAR(40) NOT NULL,
    REGISTRO_WEB BIT NOT NULL
)
GO

Create Table PEDIDOS(
    ID INT PRIMARY KEY IDENTITY(1, 1),
    IDProd SMALLINT NOT NULL FOREIGN KEY REFERENCES PRODUCTOS(Codigo),
    IDCliente SMALLINT NOT NULL FOREIGN KEY REFERENCES CLIENTES(ID),
    Cantidad SMALLINT NOT NULL CHECK(Cantidad > 0),
    Fecha_Solicitud SmallDatetime NOT NULL CHECK( Fecha_Solicitud <= GetDate()),
    Fecha_Entrega SMALLDATETIME NULL,
    Costo MONEY NOT NULL,
    Abonado BIT NOT NULL
)
GO

/*DROP TABLE PEDIDOS
GO*/

Create Table COLABORADORES(
    Legajo SMALLINT NOT NULL PRIMARY KEY,
    Apellidos VARCHAR(40) NOT NULL,
    Nombres VARCHAR(40) NOT NULL,
    Nacimiento DATE NOT NULL CHECK(Nacimiento < GetDate()),
    Edad INT NOT NULL,
    Ingreso DATE NOT NULL CHECK(Ingreso < GetDate()),
    Sueldo MONEY NOT NULL,
    Modalidad CHAR NOT NULL CHECK(Modalidad IN('F', 'P')),
)
GO

Create Table Datos_Cliente(
    IDCliente SMALLINT NOT NULL PRIMARY KEY FOREIGN KEY REFERENCES CLIENTES(ID),
    Nacimiento DATE NULL CHECK(Nacimiento < GetDate()),
    Telefono_Linea VARCHAR(15) NULL,
    Celular VARCHAR(15) NULL,
)
GO