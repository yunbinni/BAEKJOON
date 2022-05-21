#include<cstdio>
int main() {
	int n, res=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i*=10) res+=(n-i+1);
	printf("%d\n", res);
	return 0;
}
