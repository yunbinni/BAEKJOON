#include<bits/stdc++.h>
using namespace std;

struct L {
	int s;
	int e;
};

bool cmp(L A, L B) {
	return A.s<B.s;
}

int N;
L inp[104];

int dp[104];

void input() {
	cin>>N;
	for(int i=1; i<=N; i++) cin>>inp[i].s>>inp[i].e;
}

void solve() {
	int tmp=0;
	sort(inp+1, inp+N+1, cmp);
	for(int i=1; i<=N; i++) {
		dp[i]=1;
		for(int j=1; j<i; j++) {
			if(inp[j].e<inp[i].e) {
				dp[i]=max(dp[i], dp[j]+1);
			}
		}
		tmp=max(tmp, dp[i]);
	}
	cout<<N-tmp<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
