#include "rekursion.h"
#include "stdlib.h"
#include "stdio.h"

int main() {
	for (int n = 0; n < 6; n++)
		printf("%d", fibonacci(n));

	printf("\n\n\n");

	zahlenfolge(5);

	printf("\n\n\n");

	for (int n = 0; n < 6; n++)
		printf("%d ", sum(n));

	return 0;
}