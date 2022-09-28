#include<bits/stdc++.h>
using namespace std;

int n, m;
int inp[1004], dp[1004][1004];

void input() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>inp[i];
}

int DP(int i, int j) {
	if(i>n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	
	dp[i][j]=(m-j+1)*(m-j+1)+DP(i+1, inp[i]+1);
	if(j+inp[i]<=m)
		dp[i][j]=min(dp[i][j], DP(i+1, j+inp[i]+1));
	
	return dp[i][j];
}

int main() {
	input();
	memset(dp, -1, sizeof dp);
	cout<<DP(1, 0)<<"\n";
	return 0;
}
