int g(int);
int h(int);
        
int f(int x) {
    int c = x;
    int a = g(c);
    int b = a;
    a = h(c);
    a = a + b;
    return a;
}
