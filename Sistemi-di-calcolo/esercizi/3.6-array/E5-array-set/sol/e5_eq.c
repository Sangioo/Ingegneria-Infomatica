void array_set(short* v, int n, short x) {
	char* a = (char*)v;
	short c = x;
	int d = n;
	d = d * 2;
	a = a + d;
	a = a - 2;
L:  if ((short*)a < v) 
		goto E;
    *(short*)a = c;
    a = a - 2;
    goto L;
E:;
}
