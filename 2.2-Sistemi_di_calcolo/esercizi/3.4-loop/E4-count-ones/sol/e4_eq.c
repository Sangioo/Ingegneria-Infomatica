unsigned count1(unsigned n) {
    unsigned c = n;
    unsigned a = 0; // counter
L:  if (c==0) goto E;
    if ((c & 1)==0) goto K;
    a++;
K:  c = c >> 1;
    goto L;
E:  return a;
}
