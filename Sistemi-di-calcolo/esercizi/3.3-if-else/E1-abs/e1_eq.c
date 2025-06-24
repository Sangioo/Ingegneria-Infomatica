int myabs(int x) {
	int a = x;
    if (a>=0) goto L;
	a = -a;
L:
    return a;
}

