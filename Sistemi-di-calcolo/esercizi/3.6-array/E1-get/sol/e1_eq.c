short get(short* v, unsigned n, unsigned i) {
	short* c = v;
	unsigned d = i;
    if (d < n) 
		goto L;
	short ax = -1; 
    return ax;
L:  ax = d[c];
    return ax;
}
