#include <cstdio>
using namespace std;

int n, i;
int L[21], J[21];

int f(int pos, int hp, int j) {
	if(pos>n) return j;
	if(hp<=0) return 0;
	
	auto a = f(pos+1, hp-L[pos], j+J[pos]);
	auto b = f(pos+1, hp, j);
	
	return a>b?a:b;
}

int main() {
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &L[i]);
	for(i=0; i<n; i++) scanf("%d", &J[i]);
	
	printf("%d\n", f(0, 100, 0));
	
	return 0;
}
