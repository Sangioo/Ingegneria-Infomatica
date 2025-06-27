unsigned my_strlen(const char* s) {
    unsigned cnt = 0;
    while (*s++) cnt++;
    return cnt;
}
