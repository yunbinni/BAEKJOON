#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, in;
	bool flag=true;
	cin>>n;
	vector<int> v, sorted;
	for(int i=0; i<n; i++) {
		cin>>in;
		v.push_back(in);
		sorted.push_back(i+1);
	}
	next_permutation(v.begin(), v.end());
	if(v==sorted) cout<<"-1";
	else for(int e:v) cout<<e<<" ";
	return 0;
}
