#include<bits/stdc++.h>
using namespace std;

int N;
int T[16], P[16];

int res;

void f(int L, int psum) {
	if(L>N) {
		res=max(res, psum);
		return;
	}
	if(L+T[L]<=N+1) f(L+T[L], psum+P[L]);
	f(L+1, psum);
}

int main() {
	cin>>N;
	for(int i=1; i<=N; i++) cin>>T[i]>>P[i];
	f(1, 0);
	cout<<res<<"\n";
	return 0;
}
