#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> inp(1001, 0);
vector<int> dp(1001, INT_MAX);

void input() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>inp[i];
}

int solve(int idx) {
	if(dp[idx]<INT_MAX) return dp[idx];
	int rem=m-inp[idx];
	for(int i=idx+1; i<=n+1 && rem>=0; i++) {
		if(i==n+1) {dp[idx]=0; break;}
		dp[idx]=min(dp[idx], rem*rem+solve(i));
		rem-=(inp[i]+1);
	}
	return dp[idx];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	dp[n]=0;
	cout<<solve(1)<<"\n";
	return 0;
}
