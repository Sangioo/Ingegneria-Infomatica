int g(int x);

int f(int x) {
    int y = 1, z = 2;
    return g(x + 1) + y + z;
}