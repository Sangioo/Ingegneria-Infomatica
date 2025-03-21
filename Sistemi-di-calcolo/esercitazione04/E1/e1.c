int count(const char *s1){
    int a=0;
    while(*s1){
        a++;
        s1++;
    }
    return a;
}