void swap(char* x, char* y) {
    char* c = x;
    char* d = y;
    char al = *c;
    char ah = *d;
    *c = ah;
    *d = al;
}
