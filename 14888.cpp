#include<bits/stdc++.h>
using namespace std;

int n, maxN=INT_MIN, minN=INT_MAX;
int a[101], b[101];
int op[4];

void DFS(int L) {
	if(L>=n) {
		int res=a[1];
		for(int i=1; i<n; i++) {
			if(b[i]==0) res+=a[i+1];
			if(b[i]==1) res-=a[i+1];
			if(b[i]==2) res*=a[i+1];
			if(b[i]==3) res/=a[i+1];
		}
		if(res>maxN) maxN=res;
		if(res<minN) minN=res;
	}
	
	for(int i=0; i<4; i++) {
		if(op[i]>0) {
			op[i]--;
			b[L]=i;
			DFS(L+1);
			op[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=0; i<4; i++) scanf("%d", &op[i]);
	DFS(1);
	printf("%d\n%d\n", maxN, minN);
	return 0;
}
