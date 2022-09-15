#include<bits/stdc++.h>
using namespace std;

int n, k, x;

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	vector<int> inp;
	for(int i=0; i<n; i++) {
		cin>>x;
		inp.push_back(x);
	}
	sort(inp.begin(), inp.end(), greater<int>());
	cout<<inp[k-1]<<"\n";
	return 0;
}
