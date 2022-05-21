#include <iostream>
using namespace std;

int n;
int a[10], visited[10];

void f(int pos) {
	if(pos>=n) {
		for(int i=0; i<n; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(visited[i]) continue;
		visited[i]=1;
		a[pos]=i;
		f(pos+1);
		visited[i]=0;
	}
}

int main() {
	scanf("%d", &n);
	
	f(0);
	
	return 0;
}
