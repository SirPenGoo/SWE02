#include "rekursion.h"
#include "stdio.h"

int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return fibonacci(n - 2) + fibonacci(n - 1);
}

void zahlenfolge(int n) 
{

    if (n > 0)
    {
        printf("%d ", n);
        zahlenfolge(n - 1);
    }
}

int sum(int n) {
    if (n)
        return n + sum(n - 1);
    else
        return n;
}
