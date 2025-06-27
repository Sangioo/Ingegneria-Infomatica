#include "../e1.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void mem_swap(void* s1, void* s2, size_t n){
    // buffer di appooggio 
    void* tmp = malloc(n);

    // assert genera abort (errore non recuperabile)
    // se la condizione passata come argomento e'
    // falsa. assert e' usata in fase di sviluppo
    // e debug per rilevare quanto alcune
    // condizioni non sono verificate
    // ma il programmatore assume sia
    // invece verificate nel resto del codice
    assert(tmp != 0);
    
    // scambio passando su buffer di appoggio
    memcpy(tmp, s1, n);
    memcpy(s1, s2, n);
    memcpy(s2, tmp, n);
    
    // dealloco buffer di appoggio
    free(tmp);
}
