#include<bits/stdc++.h>
using namespace std;

int n, m, u, v, res;
int chk[1004];
vector<vector<int> > graph;

void DFS(int v) {
	chk[v]=1;
	for(int e : graph[v]) {
		if(chk[e]==0) DFS(e);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	graph.assign(n+1, vector<int>(0));
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1; i<=n; i++) {
		if(chk[i]==0) {
			res++;
			DFS(i);
		}
	}
	cout<<res<<"\n";
	return 0;
}
