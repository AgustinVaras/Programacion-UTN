CREATE DATABASE Clase1
GO

USE Clase1
GO
--Declaro la Tabla
CREATE TABLE Areas
(
	--Nombre, caracteristicas y separo las tablas con la ","
	ID smallint primary key identity(1, 1),  
	Nombre varchar(50) not null, 
	Presupuesto money not null check ( Presupuesto > 0 ),
	Mail varchar(120) not null unique,
)
GO

--siempre que tenga que cree una tabla nueva
--Ejecutar solo ese script o comentar scripts anteriores para evitar conflictos al crear las tablas
CREATE TABLE Empleados
(
	ID bigint not null primary key,
	--siempre al usar una foreign key el tipo de tabla tiene que existir y tiene que ser el mismo tipo de dato
	IDArea smallint null foreign key references Areas (ID),
	Apellidos varchar(100) not null,
	Nombres varchar(100) not null,
	Nacimiento date null,
)

--DROP TABLE Empleados