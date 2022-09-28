#include<bits/stdc++.h>
using namespace std;

int N, K, res;
vector<int> inp;

void input() {
	cin>>N>>K;
	inp.assign(N, 0);
	for(int i=0; i<N; i++) cin>>inp[i];
}

void solve() {
	sort(inp.begin(), inp.end());
	vector<int> rng(N-1, 0);
	for(int i=0; i<N-1; i++) rng[i]=inp[i+1]-inp[i];
	sort(rng.begin(), rng.end());
	for(int i=0; i<N-K; i++) res+=rng[i];
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
