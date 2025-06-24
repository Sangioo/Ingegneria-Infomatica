#ifndef __PERSON_T__
#define __PERSON_T__

typedef struct {
    char age;       // 0 age    |x---|
    char* name;     // 4 name   |xxxx|
    char gender;    // 8 gender |x---|
} person_t;         // sizeof == 12

void fill(person_t* p, char age, char* name, char gender);

#endif
