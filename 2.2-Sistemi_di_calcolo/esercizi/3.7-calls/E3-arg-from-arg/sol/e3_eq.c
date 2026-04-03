int g(int x);

int f(int x) {
    int a = g(x);
    a = a + 1;
    return a;
}