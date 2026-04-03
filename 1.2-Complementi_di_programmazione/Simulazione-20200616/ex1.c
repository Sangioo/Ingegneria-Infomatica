#include "aux.h"

void bombardamentoNavale(Mat *src, int r, int c){
  if (r < 0 || r >= src->rows || c < 0 || c >= src->cols) return;
  
  if (src->row_ptrs[r][c] == 0) return;
  
  src->row_ptrs[r][c] = 0;
  bombardamentoNavale(src, r-1, c);
  bombardamentoNavale(src, r, c-1);
  bombardamentoNavale(src, r+1, c);
  bombardamentoNavale(src, r, c+1);
  return;
}

