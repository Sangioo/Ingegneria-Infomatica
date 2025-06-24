int g(int);
int h(int);
        
int f(int x) {
    int b = x;
    int a = g(b);
    int di = a;
    a = h(b);
    a = di + a;
    return a;
}
