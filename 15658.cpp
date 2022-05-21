#include<bits/stdc++.h>
using namespace std;

int n, maxN=INT_MIN, minN=INT_MAX;
int a[101];
int op[4];

void DFS(int L, int cur) {
	if(L>=n) {
		if(cur>maxN) maxN=cur;
		if(cur<minN) minN=cur;
		return;
	}
	
	for(int i=0; i<4; i++) {
		if(op[i]>0) {
			op[i]--;
			if(i==0) DFS(L+1, cur+a[L+1]);
			if(i==1) DFS(L+1, cur-a[L+1]);
			if(i==2) DFS(L+1, cur*a[L+1]);
			if(i==3) DFS(L+1, cur/a[L+1]);
			op[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=0; i<4; i++) scanf("%d", &op[i]);
	DFS(1, a[1]);
	printf("%d\n%d\n", maxN, minN);
	return 0;
}
