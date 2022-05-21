#include <cstdio>
#define MAX 1000000

int n, i, j;
int a[MAX+1];

int main() {
	a[1]=1;
	for(i=2; i*i<=MAX; i++) {
		if(a[i]==0) {
			for(j=i*i; j<=MAX; j+=i) {
				a[j]=1;
			}
		}
	}
	
	while(scanf("%d", &n) && n!=0) {
		int flag=0;
		for(i=3; i<n; i+=2) {
			if(a[i]==0 && a[n-i]==0) {
				printf("%d = %d + %d\n", n, i, n-i);
				flag=1;
				break;
			}
		}
		if(flag==0) printf("Goldbach's conjecture is wrong.\n");
	}
	
	return 0;
}
