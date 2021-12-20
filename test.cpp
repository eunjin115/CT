#include <stdio.h>

int main()
{
	int n = 385;
	printf("%d %d %d", n/100, (n/10) % 10, n%10);

	return (0);
}