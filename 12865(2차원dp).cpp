#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int W[104], V[104];
	cin>>n>>k;
	vector<vector<int> > dp(n+1, vector<int>(k+1, 0)); //dp[i][j]는 i번째 물건, j번째 용량 
	for(int i=1; i<=n; i++) cin>>W[i]>>V[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			if(j>=W[i]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][k];
	return 0;
}
