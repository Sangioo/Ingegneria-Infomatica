int myabs(int x) {
    int a = x;
    if (a >= 0) goto E;
    a = -a;
E:  return a;
}
