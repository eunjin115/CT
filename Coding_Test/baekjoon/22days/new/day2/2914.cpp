#include <iostream>

int main()
{
	int A, I;
	scanf("%d %d",&A ,&I);
	printf("%d",A*(I-1)+1); //올림이므로 평균이 (I-1) 되는 멜로디 갯수보다 1을 더함
	return 0;
}