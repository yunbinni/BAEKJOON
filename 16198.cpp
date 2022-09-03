#include<bits/stdc++.h>
using namespace std;

int n, res=0;
int inp[14], cpy[14], ord[14], chk[14];

void DFS(int L) {
	if(L==n-2) {
		int tmp=0;
		for(int i=0; i<n-2; i++) {
			inp[ord[i]]=0;
			int l=ord[i]-1, r=ord[i]+1;
			while(inp[l]==0) l--;
			while(inp[r]==0) r++;
			tmp+=inp[l]*inp[r];
		}
		res=max(res, tmp);
		memcpy(inp, cpy, sizeof inp);
		return;
	}
	
	for(int i=1; i<=n-2; i++) {
		if(chk[i]==0) {
			chk[i]=1;
			ord[L]=i;
			DFS(L+1);
			chk[i]=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>inp[i];
		cpy[i]=inp[i];
	}
	DFS(0);
	cout<<res;
	return 0;
}
