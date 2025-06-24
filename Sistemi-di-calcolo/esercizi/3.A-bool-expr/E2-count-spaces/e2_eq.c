// Scrivi il C equivalente qui...

int count_spaces(const char* s) {
	const char *ecx = s;
    int eax = 0;
L:; char dl = *ecx;
	if (dl==0) goto E;
	dl = dl == 32; // ' ' ha codice 32 in ASCII
    eax += dl;
    ecx++;
	goto L;
E:  return eax;
}
