(1) SELECT DISTINCT p.nome, c.regione
    FROM Persona AS p join Citta AS c ON p.cittaNascita = c.nome
    WHERE p.eta >= 18

(2) SELECT DISTINCT c.regione
    FROM Persona AS p JOIN Citta AS c ON p.cittaNascita = c.nome JOIN Genia AS g ON p.nome = g.genitore
    WHERE p.eta > 50

(3) SELECT p1.nome AS nomeFiglio, p2.nome AS nomeGenitore
    FROM Persona AS p1 JOIN Genia AS g ON p1.nome = g.figlio JOIN Persona AS p2 ON p2.nome = g.genitore
    WHERE p1.cittaNascita = p2.cittaNascita

(4) SELECT DISTINCT g2.genitore
    FROM Genia AS g1 JOIN Genia AS g2 ON g1.genitore = g2.figlio JOIN Persona AS p ON g2.genitore = p.nome
    WHERE p.sesso = 'M'

(5) SELECT DISTINCT c.regione
    FROM Genia AS g1 JOIN Genia AS g2 ON g1.genitore = g2.figlio JOIN Persona AS p ON g2.genitore = p.nome JOIN Citta AS c ON p.cittaNascita = c.nome
    WHERE p.sesso = 'M' AND p.eta < 60

(6) SELECT DISTINCT g1.figlio AS figlio1, g2.figlio AS figlio2
    FROM Genia AS g1 JOIN Genia AS g2 ON g1.genitore = g2.genitore
    WHERE g1.figlio > g2.figlio

(7) SELECT g2.genitore AS Nonno, g3.genitore AS Nonna
    FROM Genia AS g1 JOIN Persona AS p1 ON g1.genitore = p1.nome
        JOIN Genia AS g2 ON g1.genitore = g2.figlio
        JOIN Persona AS p2 ON g2.genitore = p2.nome
        JOIN Genia AS g3 ON g1.genitore = g3.figlio
        JOIN Persona AS p3 ON g3.genitore = p3.nome
    WHERE p1.sesso = 'M' AND p2.sesso = 'M' AND p3.sesso = 'F'