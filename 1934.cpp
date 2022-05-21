#include<cstdio>

int gcd(int a, int b) {
	int r=a%b;
	if(r==0) return b;
	return gcd(b, r);
}

int lcm(int a, int b) {
	return a*b/gcd(a, b);
}

int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
	return 0;
}
