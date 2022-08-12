USE Act1_2
GO

Create Table BANDAS(
    IDBanda SMALLINT NOT NULL PRIMARY KEY,
    Cantidad_Integrantes SMALLINT NOT NULL CHECK(Cantidad_Integrantes>0),
    Nombre VARCHAR(40) NOT NULL,
    Genero VARCHAR(15) NULL CHECK(Genero in('Rock','Clasico','Pop','Jazz')),
)
GO
/*DROP TABLE BANDAS
GO*/

Alter table MUSICOS
ADD CONSTRAINT FK_IDBanda FOREIGN KEY (IDBanda)
REFERENCES BANDAS(IDBanda)
GO

