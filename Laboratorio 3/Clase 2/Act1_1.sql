CREATE DATABASE Act1_1
GO

USE Act1_1
GO

Create Table Carreras(
    ID VARCHAR(4) NOT NULL PRIMARY KEY,
    Nombre VARCHAR(40) NOT NULL,
    FechaCreacion DATE NOT NULL CHECK(FechaCreacion<getdate()),
    Mail VARCHAR(120) NOT NULL,
    Nivel VARCHAR(20) CHECK(Nivel in('Diplomaturas', 'Pregrado', 'Grado', 'Posgrado')),
)
GO

/*DROP TABLE Carreras
GO*/

Create Table Alumnos(
    Legajo int NOT NULL PRIMARY KEY IDENTITY(1000,1),
    IDCarrera VARCHAR(4) NOT NULL FOREIGN KEY REFERENCES Carreras (ID),
    Nombre VARCHAR(40) NOT NULL,
    Apellido VARCHAR(40) NOT NULL,
    FechaNacimiento DATE NOT NULL CHECK(FechaNacimiento<getdate()),
    Email VARCHAR(120) NOT NULL UNIQUE,
    Telefono INT NULL,
)
GO

/*DROP TABLE Alumnos
GO*/

Create Table Materias(
    ID SMALLINT NOT NULL IDENTITY(1,1),
    IDCarrera VARCHAR(4) NOT NULL FOREIGN KEY REFERENCES Carreras (ID),
    Nombre VARCHAR(120),
    CargaHoraria INT NOT NULL CHECK(CargaHoraria>0),
)
GO

/*DROP TABLE Materias
GO*/