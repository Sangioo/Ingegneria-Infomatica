# Definizione delle variabili
CFLAGS = -g -Wall          # Opzioni generali per tutte le compilazioni
CLNTFLAGS = -DAS_CLIENT=YES -DSERVER_HOST="\"10.8.0.1\""

# Target vpn (senza le direttive per il client)
vpn: vpn.c
	gcc $(CFLAGS) -o $@ $^

# Target client (con le direttive per il client)
client: vpn.c
	gcc $(CFLAGS) $(CLNTFLAGS) -o $@ $^

# Target predefinito
all: vpn client

# Target di pulizia
.PHONY: clean
clean:
	rm -f vpn client

# Target per creare un archivio tar.gz
archive: vpn.c Makefile
	tar -czvf project.tar.gz vpn.c Makefile