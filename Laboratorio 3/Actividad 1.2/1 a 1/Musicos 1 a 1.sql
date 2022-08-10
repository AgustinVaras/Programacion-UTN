Create Database Act1_2
GO

USE Act1_2
GO

Create Table MUSICOS(
    ID VARCHAR(4) NOT NULL PRIMARY KEY,
    Nombre VARCHAR(40) NOT NULL,
    Apellido VARCHAR(40) NOT NULL,
    
)
GO

Create Table INSTRUMENTOS_MUSICO(
    IDMusico VARCHAR(4) NOT NULL FOREIGN KEY references MUSICOS (ID),
    Tipo VARCHAR(20) NOT NULL CHECK(Tipo in('Percucion', 'Aire', 'Cuerda')),
    Marcha VARCHAR(40) NULL,
)