// Si consideri il seguente calcolo:
//
// float sum = 0;
// for (int i = 0; i < 10; ++i)
// {
//   sum += 0.1f;
// }
//
// Si stampi il valore di sum, e si controlli se (sum == 1.0f).
// In caso quest’ultimo test fallisca, si sostituisca l’uguaglianza con un test appropriato per confrontare numeri in virgola mobile.
#include <stdio.h>
#include <math.h>

int main() {
    float sum = 0;

    for (int i = 0; i < 10; ++i) {
    	sum += 0.1f;
    }

	printf("sum: %f\n", sum);
	printf("(sum == 1.0f): %d\n", sum == 1.0f);
	
	if (fabs(sum - 1.0f) < 1e-6) {
		printf("sum == 1.0f\n");
	} else {
		printf("sum != 1.0f\n");
	}
	
	return 0;
}