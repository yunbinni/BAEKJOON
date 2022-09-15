#include<bits/stdc++.h>
using namespace std;

int n, s, m;
int V[54];

bool dp[54][1004];

int res=-1;

void input() {
	cin>>n>>s>>m;
	for(int i=1; i<=n; i++) cin>>V[i];
}


void solve() {
	if(s-V[1]>=0) dp[1][s-V[1]]=true;
	if(s+V[1]<=m) dp[1][s+V[1]]=true;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(dp[i-1][j]==true) {
				if(j-V[i]>=0) dp[i][j-V[i]]=true;
				if(j+V[i]<=m) dp[i][j+V[i]]=true;
			}
		}
	}
}


void output() {
	for(int i=0; i<=m; i++) if(dp[n][i]==true) res=max(res, i);
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
