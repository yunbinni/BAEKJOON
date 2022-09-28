#include<bits/stdc++.h>
using namespace std;

int T, W, res;
int inp[1004], dp[31][3][1004];

void input() {
	cin>>T>>W;
	for(int i=1; i<=T; i++) cin>>inp[i];
}

void solve() {
	for(int w=0; w<=W; w++) {
		for(int t=1; t<=T; t++) {
			
			if(w==0)
				dp[w][1][t]=dp[w][1][t-1]+(inp[t]==1);
			
			else {
				dp[w][1][t]=max(dp[w][1][t-1]+(inp[t]==1), dp[w-1][2][t-1]+(inp[t]==1));
				dp[w][2][t]=max(dp[w][2][t-1]+(inp[t]==2), dp[w-1][1][t-1]+(inp[t]==2));
			}
		}
	}
}

void output() {
	for(int w=0; w<=W; w++) for(int l=1; l<=2; l++)
		res=max(res, dp[w][l][T]);
	cout<<res<<"\n";
}

int main() {
//	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
