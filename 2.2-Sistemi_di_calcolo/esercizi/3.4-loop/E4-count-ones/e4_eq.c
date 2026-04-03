unsigned count1(unsigned n) {
    unsigned c = n;
    unsigned a = 0; 		// counter
L:  if (c<=0) goto E;
	unsigned d = c & 1;
    if (d==0) goto T;
    a++;
T:  c = c >> 1;
    goto L;
E:  return a;
}
