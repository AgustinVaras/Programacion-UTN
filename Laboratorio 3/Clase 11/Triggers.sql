-- TRIGGERS

-- *Ejecuta código T-SQL de manera desatendida.

-- *Se ejecutan automáticamente cuando ocurre una acción sobre una tabla 
-- de la base de datos. Las acciones son agrega, modificar o eliminar.

-- *El código del triger se puede ejecutar luego de la acción que lo dispara 
-- o en lugar de la acción que lo dispara. 

-- *Dentro del ámbito de un trigger existen tablas temporales que contienen 
-- los datos entrantes llamada inserted y los datos salientes llamada deleted. 
-- Éstos dependen de la acción que dispara el trigger. 

---------------------------------------------------------------------------------------------

--  TIPOS DE TRIGGERS 

--  INSTEAD OF 
--  El trigger del tipo instead of, al momento de dispararse, captura y no ejecuta 
--  la consulta de acción que lo generó y ejecuta el código definido en el trigger.

--  AFTER 
--  El trigger del tipo after, al momento de dispararse, ya ejecutó la consulta que 
--  lo generó y luego ejecuta el código definido en el trigger.

--------------------------------------------------------------------------------------------- 

-- TABLA INSERTED Y DELETED 

-- Durante la ejecución de un trigger existen dos tablas temporales que contienen 
-- los datos que están siendo ingresados o eliminados. Los mismos se encuentran 
-- almacenados en las tablas inserted y deleted respectivamente. 
---------------------------------------------------------
-- Consulta         | Datos en la tabla temporal
---------------------------------------------------------
-- Insert           | Inserted 
-- Delete           | Deleted 
-- Update           | inserted -los datos entrantes 
--                  | deleted -los datos salientes

----------------------------------------------------------------------------------------------

-- Ejemplos 
