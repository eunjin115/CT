#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", n * (m % 10));
	printf("%d\n", n * ((m / 10) % 10));
	printf("%d\n", n * (m / 100));
	printf("%d\n", n * m);

	return (0);
}