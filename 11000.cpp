#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, res=0;
	vector<pair<int, int> > inp;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin>>n;
	for(int i=0; i<n; i++) {
		int a, b;
		cin>>a>>b;
		inp.push_back(make_pair(a, b));
	}
	sort(inp.begin(), inp.end());
	pq.push(inp[0].second);
	for(int i=1; i<n; i++) {
		int s=inp[i].first;
		int t=inp[i].second;
		if(s>=pq.top()) pq.pop();
		pq.push(t);
	}
	cout<<pq.size();
	return 0;
}
