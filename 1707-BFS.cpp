#include<bits/stdc++.h>
#include<queue>
using namespace std;

int K, V, E, u, v;
vector<vector<int> > graph;
vector<int> col;

void BFS(int sv) {
	queue<int> Q;
	col[sv]=1;
	Q.push(sv);
	while(!Q.empty()) {
		int cur=Q.front();
		Q.pop();
		for(int go:graph[cur]) {
			if(col[go]==0) {
				col[go]=col[cur]*-1;
				Q.push(go);
			}
		}
	}
}

bool check() {
	for(int s=1; s<=V; s++) {
		for(int e:graph[s]) {
			if(col[s]==col[e]) return false;
		}
	}
	return true;
}

int main() {
	cin>>K;
	while(K--) {
		cin>>V>>E;
		graph.assign(V+1, vector<int>(0, 0));
		col.assign(V+1, 0);
		while(E--) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for(int i=1; i<=V; i++) {
			if(col[i]==0) BFS(i);
		}
		if(check()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
