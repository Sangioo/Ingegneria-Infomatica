int count_spaces(const char* s) {
    int cnt = 0;
    while (*s) cnt += *s++ == ' '; // ' ' ha codice 32 in ASCII
    return cnt;
}
