USE Act1_2
GO

CREATE TABLE ALBUM(
    IDAlbum INT NOT NULL PRIMARY KEY IDENTITY (100,100),
    Nombre VARCHAR(30) NOT NULL,
    Cant_Canciones SMALLINT NOT NULL,
    Fecha_Salida DATE NOT NULL,
)
GO
/*DROP TABLE ALBUM
GO*/


CREATE TABLE CANCIONES_ALBUM(
    IDAlbum INT NOT NULL FOREIGN KEY REFERENCES ALBUM(IDAlbum),
    IDCancion INT NOT NULL PRIMARY KEY IDENTITY(10, 1), 
    Nombre VARCHAR(50) NOT NULL,
    Duracion SMALLINT NOT NULL CHECK(Duracion>0),
)
GO
/*DROP TABLE CANCIONES_ALBUM
GO*/