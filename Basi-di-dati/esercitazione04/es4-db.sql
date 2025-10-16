(1) CREATE TABLE Automobile (
        Targa varchar(7) not null primary key,
        Cilindrata int,
        Citta varchar(30) not null 
    );

    CREATE TABLE Garage (
        Codice varchar(5) not null primary key,
        Citta varchar(30)
    );

    CREATE TABLE Custodita (
        TargaAuto varchar(7) not null references Automobile(Targa),
        CodGarage varchar(5) not null references Garage(Codice),
        Numero int,
        constraint pk1 primary key (TargaAuto, CodGarage),
        constraint numAuto check(Numero > 0)
    );

    INSERT INTO automobile (targa, cilindrata, citta) VALUES
    ('A1', 500, 'Roma'),
    ('A2', 1200, 'Roma'),
    ('A3', 900, 'Milano'),
    ('A4', 1000, 'Firenze'),
    ('A5', 2000, 'Palermo'),
    ('A6', 3000, 'Torino'),
    ('A7', 2000, 'Torino'),
    ('A8', 4000, 'Roma'),
    ('A9', 4000, 'Napoli'),
    ('A10', 2500, 'Siena');

    INSERT INTO garage (codice, citta) VALUES
    ('G1', 'Roma'),
    ('G2', 'Firenze'),
    ('G3', 'Firenze'),
    ('G4', 'Milano'),
    ('G5', 'Milano'),
    ('G6', 'Palermo'),
    ('G7', 'Roma'),
    ('G8', 'Palermo'),
    ('G9', 'Roma'),
    ('G10', 'Milano'),
    ('G11', 'Roma'),
    ('G12', 'Siena');

    INSERT INTO custodita (targaauto, codgarage, numero) VALUES
    ('A1', 'G1', 2),
    ('A1', 'G2', 1),
    ('A3', 'G5', 1),
    ('A2', 'G6', 15),
    ('A2', 'G7', 17),
    ('A5', 'G6', 18),
    ('A5', 'G1', 2),
    ('A4', 'G3', 1),
    ('A6', 'G1', 1),
    ('A5', 'G8', 1),
    ('A8', 'G9', NULL),
    ('A8', 'G2', 3),
    ('A10', 'G12', 5);


(2) 
1.  DELETE FROM Custodita WHERE TargaAuto = 'A10' AND CodGarage = 'G12';
    DELETE FROM Automobile WHERE citta = 'Siena';

2.  UPDATE Custodita SET Numero = 1 WHERE Numero IS NULL;


(3) 
1.  SELECT targaauto, codgarage, citta
    FROM custodita, garage
    WHERE numero = 1 AND codgarage = codice
    ORDER BY targaauto;

2.  SELECT DISTINCT G.citta, A.targa, sum(C.numero)
    FROM Automobile as A, Custodita as C, Garage as G
    WHERE A.targa = C.targaAuto and C.codgarage = G.codice and A.cilindrata > 100
    GROUP BY (G.citta, A.targa)
    HAVING sum(C.numero) > 10;

3.  SELECT g.codice, sum(c.numero) as numcomplessivo
    FROM garage as g, custodita as c
    WHERE g.codice = c.codgarage
    GROUP BY g.codice
    HAVING sum(c.numero) > 0;

4.  SELECT g.codice, sum(c.numero) as numcomplessivo
    FROM garage as g, custodita as c
    WHERE g.codice = c.codgarage
    GROUP BY g.codice
    HAVING sum(c.numero) > 10 or sum(c.numero) IS NULL;

5.  SELECT a.targa, sum(c.numero), count(c.codgarage)
    FROM automobile as a, custodita as c, garage as g
    WHERE a.targa = c.targaauto and c.codgarage = g.codice and a.citta = g.citta
    GROUP BY a.targa;

6.  SELECT codice FROM garage
    EXCEPT
    SELECT DISTINCT g.codice
    FROM garage as g, custodita as c, automobile as a
    WHERE g.codice = c.codgarage and c.targaauto = a.targa and a.citta = 'Roma';

7.  SELECT codice FROM garage
    EXCEPT
    SELECT g.codice
    FROM automobile as a JOIN custodita as c ON a.targa = c.targaauto JOIN garage as g ON c.codgarage = g.codice
    WHERE a.citta != g.citta
    GROUP BY g.codice

8.  SELECT a.targa, g.citta
    FROM automobile as a CROSS JOIN garage as g
    EXCEPT
    SELECT a.targa, g.citta
    FROM automobile as a JOIN custodita as c ON a.targa = c.targaauto JOIN garage as g ON c.codgarage = g.codice

9.  SELECT a.targa, count(DISTINCT g.citta)
    FROM automobile as a JOIN custodita as c ON a.targa = c.targaauto JOIN garage as g ON c.codgarage = g.codice
    GROUP BY a.targa
    UNION
    SELECT a.targa, 0
    FROM automobile as a LEFT JOIN custodita as c ON a.targa = c.targaauto
    WHERE c.targaauto IS NULL

10. SELECT a.targa, c.codgarage
    FROM automobile as a JOIN custodita as c ON a.targa = c.targaauto
    EXCEPT
    SELECT a.targa, c1.codgarage
    FROM automobile as a JOIN custodita as c1 ON a.targa = c1.targaauto JOIN custodita as c2 ON a.targa = c2.targaauto
    WHERE c1.numero < c2.numero
    GROUP BY (a.targa, c1.numero, c1.codgarage)