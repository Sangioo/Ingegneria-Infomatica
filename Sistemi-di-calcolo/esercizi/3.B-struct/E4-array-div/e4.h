typedef struct {
    int quot;
    int rem;
} div_rem_t;

void array_div(const int *a, const int *b, div_rem_t *res, int n);
