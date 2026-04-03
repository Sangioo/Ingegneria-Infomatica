print("--- Registrazione Dati Studente ---")
completed = False
while not completed:
    print("\n")
    matricola = input("inserire MATRICOLA: ").strip()
    if not matricola.isdigit():
        print("\nMatricola non valida")
        continue
    print("\n")
    cognome = input("inserire COGNOME: ").strip().lower()
    print("\n")
    nome = input("inserire NOME: ").strip().lower()
    print("\n")
    print("Confermi i seguenti dati?\n")
    print("MATRICOLA:",matricola)
    print("COGNOME:",cognome)
    print("NOME:",nome)
    while True:
        print("\n")
        risp = input("Premere S o N: ").strip().lower()
        if risp == "n":
            break
        elif risp == "s":
            try:
                with open("studente.txt", "w") as f:
                    f.write(matricola+"\n")
                    f.write(cognome+"\n")
                    f.write(nome)
                input("\nRegistrazione dati studente completata, premere INVIO per chiudere\n")
                completed = True
                break
            except:
                print("PROBLEMA CONSEGNA COMPITO")
                input()
        completed = True
        break
