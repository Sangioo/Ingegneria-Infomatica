int g();
int h();
        
int f(int x) {
    int a = g();
    // solutione con EBX
    int b = a;
    // solution con ECX
    int c = a;
    a = h();
    // solutione con EBX
    a = a + b;
    // solution con ECX
    a = a + c;
    return a;
}
