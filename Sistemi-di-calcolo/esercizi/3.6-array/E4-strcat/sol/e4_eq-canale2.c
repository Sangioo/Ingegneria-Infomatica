char* my_strcat(char* dest, const char* src) {
    // d <= s/dest, c <= src, a = ...
    char* s = dest;
    L: if (*s = 0) goto E;
        s++;
    jmp L;
    E;: char x = *src;
    *s = x;
    if (*s = 0) goto F;
        s++;
        src++;
    goto E;
    F: return dest;
}