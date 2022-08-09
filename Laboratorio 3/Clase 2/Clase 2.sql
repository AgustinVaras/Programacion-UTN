Create DATABASE Clase2
GO

Use Clase2
GO

Create Table Empleados(
    DNI BIGINT NOT NULL UNIQUE,
    IDArea int NOT NULL,
    Nombre VARCHAR(40) NOT NULL,
    Apellido VARCHAR(40) NOT NULL,
    Email VARCHAR(120) NULL UNIQUE,  
)
GO

Create Table Areas(
    ID int NOT NULL IDENTITY(100, 100),
    Nombre VARCHAR(40),
    Presupuesto money NULL,
)
GO

Alter Table Empleados
Add FechaNacimiento date null
GO

Alter Table Areas
Add CONSTRAINT PK_Areas Primary Key (ID)
GO

Alter Table Areas
Add CONSTRAINT CHK_Presupuesto Check(Presupuesto>0)
GO

Alter Table Empleados
Add CONSTRAINT FK_IDArea Foreign key (IDArea)
References Areas(ID) 
GO
