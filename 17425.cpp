#include<cstdio>
#include<vector>
#define MAX 1000000
using namespace std;

int main(){
	int n, i, j, t;
	scanf("%d",&t);
	vector<long> f(MAX+1, 1);
	vector<long> d(MAX+1);
	
	for(i=2; i<=MAX; i++) {
		for(j=1; i*j<=MAX; j++) {
			f[i*j]+=i;
		}
	}
	
	for(i=1; i<=MAX; i++)
		d[i]=d[i-1]+f[i];
	
	while(t--) {
		scanf("%d", &n);
		printf("%ld\n", d[n]);
	}
	
	return 0;
}
