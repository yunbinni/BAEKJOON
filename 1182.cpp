#include <stdio.h>
using namespace std;

int n, s, i, cnt;
int in[21], out[21], visited[21];

void f(int pos, int start, int size) {
	int i;
	if(pos>size) {
		int sum=0;
		for(i=1; i<=size; i++) sum+=out[i];
		if(sum==s) cnt++;
		return;
	}
	
	for(i=start; i<=n; i++) {
		out[pos]=in[i];
		f(pos+1, i+1, size);
	}
}

int main() {
	scanf("%d %d", &n, &s);
	for(i=1; i<=n; i++) scanf("%d", &in[i]);
	
	for(i=1; i<=n; i++) f(1, 1, i);
	
	printf("%d\n", cnt);
	
	return 0;
}
