## Domanda 1

Relativamente al seguente codice C (supponendo che la fork non generi un errore), quale tra le seguenti affermazioni è VERA?

- [ ] A. Viene stampato “Padre: 1” e poi “Figlio: 2”
- [ ] B. Viene stampato “Figlio: 2” e poi “Padre: 1”
- [x] C. Viene stampato “Figlio: 1” e poi “Padre: 1”
- [ ] D. Viene stampato “Figlio: 1” e poi “Padre: 2”
- [ ] E. Viene stampato “Figlio: 2” e poi “Padre: 2”
- [ ] F. L’ordine delle stampe è impredicibile, poiché dipende dallo scheduler
- [ ] G. Nessuna delle precedenti

## Domanda 2

Relativamente al seguente codice C (supponendo che la fork non generi un errore), qual è l’output atteso?

- [x] A. Nell’ordine (una per linea): “Figlio 1: x=10”, “Figlio 2: x=20”, “Figlio 3: x=30”, “Padre: x=40”
- [ ] B. Nell’ordine (una per linea): “Figlio 1: x=10”, “Figlio 2: x=10”, “Figlio 3: x=10”, “Padre: x=30”
- [ ] C. Nell’ordine (una per linea): “Figlio 1: x=10”, “Figlio 2: x=10”, “Figlio 3: x=10”, “Padre: x=40”
- [ ] D. Nell’ordine (una per linea): “Figlio 1: x=10”, “Figlio 2: x=20”, “Figlio 3: x=30”, “Padre: x=30”
- [ ] E. Nell’ordine (una per linea): “Figlio 1: x=10”, “Figlio 2: x=30”, “Figlio 3: x=60”, “Padre: x=100”
- [ ] F. L’ordine delle stampe è impredicibile, poiché dipende dallo scheduler
- [ ] G. Nessuna delle precedenti

## Domanda 3

Relativamente al seguente codice C (supponendo che la execv non generi un errore), qual è l’output atteso?

- [ ] A. Nell’ordine (una per linea): “--- started ---”, “Hello”, “NULL, “--- finished ---”
- [x] B. Nell’ordine (una per linea): “--- started ---”, “Hello”, “--- finished ---”
- [ ] C. Nell’ordine (una per linea): “--- started ---”, “Hello”
- [ ] D. Nell’ordine (una per linea): “--- started ---”, “--- finished ---”
- [ ] E. L’ordine delle stampe è impredicibile, poiché dipende dallo scheduler
- [ ] F. Nessuna delle precedenti
