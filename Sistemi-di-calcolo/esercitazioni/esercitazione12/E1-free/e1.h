#ifndef __E1__
#define __E1__
    
#pragma pack(1)
typedef struct header_t {
    unsigned size;
    struct header_t* next;
} header_t;

void* mymalloc(size_t m);
void myfree(void* p);

#endif
