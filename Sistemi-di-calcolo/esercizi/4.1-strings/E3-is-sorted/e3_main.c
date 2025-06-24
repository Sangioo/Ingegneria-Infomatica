#include <stdio.h>
#include <stdlib.h>
#include "e3.h"

// la funzione is_sorted deve verificare se l'array di stringhe è ordinato in 
// senso lessicografico

int main() {
    char *icao[] = { "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", 
                     "Golf", "Hotel", "India", "Juliet", "Kilo", "Lima", 
                     "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                     "Sierra", "Tango", "Uniform", "Victor", "Whiskey", 
                     "X-ray", "Yankee", "Zulu" };

    char *err[] = { "one", "two", "three", "four" };

    int res = is_sorted(icao, 26);    
    printf("Test 1: %s\n", res == 0 ? "OK" : "Err");

    res = is_sorted(err, 4);    
    printf("Test 2: %s\n", res == 0 ? "OK" : "Err");
    
    return 0;
}
