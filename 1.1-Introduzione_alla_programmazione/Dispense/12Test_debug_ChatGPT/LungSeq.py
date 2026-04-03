def lunghezza_sequenza_non_decrescente(numeri):
    if not numeri:
        return 0

    lunghezza_sequenza = 1
    lunghezza_corrente = 1

    for i in range(1, len(numeri)):
        if numeri[i] >= numeri[i - 1]:
            lunghezza_corrente += 1
        else:
            if lunghezza_corrente > lunghezza_sequenza:
                lunghezza_sequenza = lunghezza_corrente
            lunghezza_corrente = 1

    # Controlla l'ultima sequenza
    if lunghezza_corrente > lunghezza_sequenza:
        lunghezza_sequenza = lunghezza_corrente

    return lunghezza_sequenza

# Esempio di utilizzo:
lista_numeri = [1, 2, 3, 2, 5, 7, 2, 4, 6, 8, 10]
risultato = lunghezza_sequenza_non_decrescente(lista_numeri)
print("Lunghezza della sequenza non decrescente più lunga:", risultato)
