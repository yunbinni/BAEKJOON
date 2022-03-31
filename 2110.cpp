#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

int f(int len, int x[]) {
	int i, ret=1, pos=x[1];
	for(i=2; i<=n; i++) {
		if(x[i]-pos>=len) {
			ret++;
			pos=x[i];
		}
	}
	return ret;
}

int main() {
	int c, lt, rt, mid, res, i;
	scanf("%d %d", &n, &c);
	int *x = new int[n+1];
	for(i=1; i<=n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	lt=1; rt=x[n];
	
	while(lt<=rt) {
		mid=(lt+rt)/2;
		if(f(mid, x)>=c) {
			res=mid;
			lt=mid+1;
		}
		else rt=mid-1;
	}
	printf("%d\n", res);
	delete[] x;
	return 0;
}
