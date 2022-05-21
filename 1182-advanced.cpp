#include <stdio.h>
using namespace std;

int n, s, cnt;
int in[20];

void sol(int idx, int sum) {
	sum+=in[idx];
	if(idx>=n) return;
	if(sum==s) cnt++;
	sol(idx+1, sum-in[idx]);
	sol(idx+1, sum);
}

int main() {
	scanf("%d %d", &n, &s);
	
	for(int i=0; i<n; i++) scanf("%d", &in[i]);
	
	sol(0, 0);
	
	printf("%d\n", cnt);
	
	return 0;
}
