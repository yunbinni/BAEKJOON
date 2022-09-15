#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> inp, dp;

void input() {
	cin>>n;
	inp.assign(n+1, 0);
	dp.assign(n+1, 0);
	dp[0]=-1001;
	for(int i=1; i<=n; i++) cin>>inp[i];
}

void solve() {
	for(int i=1; i<=n; i++) {
		dp[i]=max(dp[i-1]+inp[i], inp[i]);
	}
}

void output() {
	cout<<*max_element(dp.begin(), dp.end())<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
