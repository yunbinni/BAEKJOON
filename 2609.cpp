#include<cstdio>

int Euc(int a, int b) {
	int r = a%b;
	if(r==0) return b;
	return Euc(b, r);
}

int main() {
	int a, b, gcd;
	scanf("%d %d", &a, &b);
	gcd=Euc(a, b);
	printf("%d\n", gcd);
	printf("%d\n", (a/gcd)*(b/gcd)*gcd);
	return 0;
}
