int g(int x);

int f(int x) {
    int b = 1, bp = 2;
    int c = x;
    int a = g(c + 1);
    a = a + b;
    a = a + bp;
    return a;
}