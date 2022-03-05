#include <cstdio>

int A, B, C;

int main() {
	scanf("%d %d", &A, &B);
	scanf("%d", &C);
	
	A = (A + (B + C)/60)%24;
	B = (B + C) % 60;
	
	printf("%d %d", A, B);
	
	return 0;
}
