int mcd(int x, int y) {
	int a = x;
	int c = y;
L:  if (c==0) goto E;
    int b = c;
    int d = a;
    d = d >> 31;
    d = a % c;
	c = d;
    a = b;
    goto L;
E:  return a;
}
