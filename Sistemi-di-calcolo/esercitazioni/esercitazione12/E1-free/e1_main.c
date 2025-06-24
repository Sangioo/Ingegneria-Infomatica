#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "e1.h"

extern header_t* free_list;

char* heap;

void init_heap() {
    heap = sbrk(0);
}

int is_free(void* b) {
    header_t* p;
    for (p = free_list; p != NULL; p = p->next)
        if (p == b) return 1;
    return 0;
}

void print_free() {
    header_t* p;
    printf("=== free_list: %p\n", free_list);
    for (p = free_list; p != NULL; p = p->next)
        printf("*   [%p][size=%-4u][next=%p]\n", p, p->size, (char*)p->next);
}

void print_heap() {
    char* p = heap;
    char* cur_heap = sbrk(0);    
    unsigned i = 1;
    printf("--- heap size: %lu byte\n", cur_heap - heap);
    while (heap < cur_heap) {
        printf("%-3u [%p][size=%-4u][%s]\n", i, heap, ((header_t*)heap)->size, is_free(heap) ? "free" : "used");
        heap += 4 + ((header_t*)heap)->size;
        i++;
    }
}

int main() {
    init_heap();
    void* p1 = mymalloc(16);
    void* p2 = mymalloc(22);
    void* p3 = mymalloc(8);
    void* p4 = mymalloc(12);
    myfree(p1);
    myfree(p3);
    void* p5 = mymalloc(4);
    void* p6 = mymalloc(14);
    myfree(p5);
    myfree(p6);
    print_heap();
    print_free();
    return EXIT_SUCCESS;
}
