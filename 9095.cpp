#include<bits/stdc++.h>
using namespace std;

int t, n, cnt;

void DFS(int sum) {
	if(sum==n) {
		cnt++;
		return;
	}
	if(sum>n) return;
	
	DFS(sum+1);
	DFS(sum+2);
	DFS(sum+3);
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		DFS(0);
		printf("%d\n", cnt);
		cnt=0;
	}
	return 0;
}
