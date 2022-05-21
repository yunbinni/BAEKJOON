#include<cstdio>

int gcd(int a, int b) {
	int r=a%b;
	if(r==0) return b;
	return gcd(b, r);
}

int lcm(int a, int b) {
	return a*b/gcd(a, b);
}

int f(int m, int n, int x, int y) {
	int cnt=x;
	int ny=x%n;
	int lim=lcm(m, n);
	while(cnt<=lim) {
		int ty=ny%n==0?n:ny%n;
		if(ty==y) return cnt;
		cnt+=m;
		ny=(ny+m)%n;
	}
	return -1;
}

int main() {
	int t, m, n, x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &m, &n, &x, &y);
		printf("%d\n", f(m, n, x, y));
	}
	return 0;
}
