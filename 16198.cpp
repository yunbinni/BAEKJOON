#include<bits/stdc++.h>
using namespace std;

int n, res=0;
int inp[14], cpy[14], ord[14];
bool chk[14];

void input() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>inp[i];
	memcpy(cpy, inp, sizeof cpy);
}

void DFS(int L) {
	if(L==n-2) {
		int tmp=0;
		for(int i=0; i<n-2; i++) {
			cpy[ord[i]]=0;
			int l=ord[i]-1, r=ord[i]+1;
			while(cpy[l]==0) l--;
			while(cpy[r]==0) r++;
			tmp+=cpy[l]*cpy[r];
		}
		res=max(res, tmp);
		memcpy(cpy, inp, sizeof cpy);
		return;
	}
	
	for(int i=1; i<=n-2; i++) {
		if(!chk[i]) {
			chk[i]=true;
			ord[L]=i;
			DFS(L+1);
			chk[i]=false;
		}
	}
}

void output() {
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	DFS(0);
	output();
	return 0;
}
