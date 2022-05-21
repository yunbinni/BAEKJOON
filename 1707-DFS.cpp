#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

int K, V, E, u, v;
vector<int> graph[20004];
int col[20004];

void DFS(int vtx, int color) {
	if(col[vtx]==0) {
		col[vtx]=color;
		for(int go:graph[vtx]) DFS(go, -1*color);
	}
}

bool check(int n) {
	for(int s=1; s<=n; s++) {
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
		for(int i=0; i<E; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
            graph[v].push_back(u);
		}
		
		//수정부분 
		for(int i=1; i<=V; i++) {
			if(col[i]==0) DFS(i, 1);
		}
		
		if(check(V)) cout<<"YES\n";
		else cout<<"NO\n";
		
		for(int i=0; i<20004; i++) graph[i].clear();
		memset(col, 0, sizeof(int)*20004);
	}
	return 0;
}
