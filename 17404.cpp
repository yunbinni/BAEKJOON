#include<bits/stdc++.h>
using namespace std;

int n, res=2147000000;
int inp[1004][3];

void input() {
	cin>>n;
	for(int i=1; i<=n; i++) cin>>inp[i][0]>>inp[i][1]>>inp[i][2];
}

void solve() {
	for(int s=0; s<3; s++) {
		int dp[1004][3];
		for(int i=0; i<3; i++) {
			if(i==s) dp[1][s]=inp[1][s];
			else dp[1][i]=2147000000;
		}
		for(int i=2; i<=n; i++) {
			dp[i][0]=min(dp[i-1][1], dp[i-1][2])+inp[i][0];
			dp[i][1]=min(dp[i-1][0], dp[i-1][2])+inp[i][1];
			dp[i][2]=min(dp[i-1][0], dp[i-1][1])+inp[i][2];
		}
		for(int i=0; i<3; i++) {
			if(i==s) continue;
			res=min(res, dp[n][i]);
		}
	}
}

void output() {
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
