#ifndef __E2__
#define __E2__

struct contatto {
    char nomecompleto[32];   	// Destinazione del collegamento
    char numero[16];
};

int cerca(const char * filename, const char * prefix, struct contatto ** arrayMatches);

#endif
