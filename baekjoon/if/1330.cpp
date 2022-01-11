#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d",&n, &m);

	if (n > m)
		printf(">");
	else if (n < m)
		printf("<");
	else
		printf("==");

	return (0);
}