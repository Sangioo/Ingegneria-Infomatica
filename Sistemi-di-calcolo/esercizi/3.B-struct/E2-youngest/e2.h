#ifndef __PERSON_T__
#define __PERSON_T__

typedef struct {    // base
    char gender;    // offset: 0 |x...|    (base)
    char* name;     // offset: 4 |xxxx|   4(base)
    char age;       // offset: 8 |x...|   8(base)
} person_t;         // sizeof: 12

#endif
