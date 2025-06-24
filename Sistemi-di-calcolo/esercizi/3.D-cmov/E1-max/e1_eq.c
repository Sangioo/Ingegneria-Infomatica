int max(int x, int y) {
	int a = x;
	int c = y;
	if (c<=a) goto E;
	a=c;
E:  return a;
}
