int f(int x, int n) {
   int s = 1;
   for (; n>0; n--) s *= 7+x;
   return s;
}
