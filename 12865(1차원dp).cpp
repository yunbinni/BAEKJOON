#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int W[104], V[104];
	cin>>n>>k;
	vector<int> dp(k+1);
	for(int i=1; i<=n; i++) cin>>W[i]>>V[i];
	for(int i=1; i<=n; i++) {
		for(int j=k; j>=1; j--) {
			if(j>=W[i]) dp[j]=max(dp[j], dp[j-W[i]]+V[i]);
		}
	}
	cout<<dp[k];
	return 0;
}
