// Inserisci qui il C equivalente

/*
typedef struct {
    char age;       // 0 age    |x---|
    char* name;     // 4 name   |xxxx|
    char gender;    // 8 gender |x---|
} person_t;         // sizeof == 12
*/

#include "e1.h"

void fill(person_t* p, char age, char* name, char gender) {
    person_t* a = p;
    char c  = age;
    char* d = name;
    char b  = gender;
    a->age = c;
    a->name = d;
    a->gender = b;
}
