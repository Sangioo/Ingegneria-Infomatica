#include <stdio.h>
#include <string.h>
#include "e4.h"

// la funzione convert_date deve convertire una data della forma
// gg/mm/aaaa in mm/gg/aaaa e viceversa

int main() {
    char buffer[] = "xx/xx/xxxx";
    
    int res = convert_date("25/2/2020", buffer);    
    printf("Test: %s\n", !strcmp(buffer, "2/25/2020") ? "OK" : "Err");
    
    return 0;
}
