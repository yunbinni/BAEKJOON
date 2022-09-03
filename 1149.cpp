#include<bits/stdc++.h>
using namespace std;

int n;
int inp[1004][3];

int dp[1004][3];

void input() {
	cin>>n;
	for(int i=1; i<=n; i++) cin>>inp[i][0]>>inp[i][1]>>inp[i][2];
}

void solve() {
	dp[1][0]=inp[1][0], dp[1][1]=inp[1][1], dp[1][2]=inp[1][2];
	for(int i=2; i<=n; i++) {
		dp[i][0]=min(dp[i-1][1], dp[i-1][2])+inp[i][0];
		dp[i][1]=min(dp[i-1][0], dp[i-1][2])+inp[i][1];
		dp[i][2]=min(dp[i-1][0], dp[i-1][1])+inp[i][2];
	}
}

void output() {
	cout<<min({dp[n][0], dp[n][1], dp[n][2]})<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
