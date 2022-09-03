#include<bits/stdc++.h>
using namespace std;

int n, m, res=0;
int grp[504][504], chk[504];

int main() {
	chk[1]=1;
	cin>>n>>m;
	vector<vector<int> > grp(n+1, vector<int>(0));
	for(int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}
	for(int i : grp[1]) {
		chk[i]=1;
		res++;
	}
	for(int i : grp[1]) {
		for(int j : grp[i]) {
			if(chk[j]==0) {
				chk[j]=1;
				res++;
			}
		}
	}
	cout<<res;
	return 0;
}
