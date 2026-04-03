int is_negative(int x);

unsigned f(int *v, unsigned n) {
	int* r12 = v;  		// e12 <-> v
	unsigned r13d = n;	// r13d <-> n
    unsigned r14d = 0;  // r14d <-> cnt
	unsigned ebx = 0;   // ebx <-> i
L:  if (ebx >= r13d) 
		goto E;
	int edi = r12[ebx];	
    unsigned eax = is_negative(edi);
    r14d += eax;
	ebx++;
    goto L;
E:  eax = r14d;
    return eax;
}

