#include "e1.h"

void fill(person_t* p, char age, char* name, char gender) {
	person_t* a = p;
	
	char c = age;
    p->age = c;		// equivalente a (*p).age = c
 
	char* d = name;
    p->name = d;
    
    c = gender;
    p->gender = c;
}
