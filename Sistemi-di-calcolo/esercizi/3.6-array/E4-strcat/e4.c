char* my_strcat(char* dest, const char* src) {
    char* s = dest;
    while (*dest) dest++;
    while (*dest = *src) {
        dest++;
        src++;
    }
    return s;
}

// A = B in C è un'espressione che vale B e
//       come effetto collaterale
//       assegna B ad A
