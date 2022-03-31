#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m, v, a, b;
vector<int> adj[1004];

set<int> store; //방문한곳 저장소 

void dfs(int here) {
	store.insert(here);
	cout << here << " ";
	for(int there : adj[here]) {
		if(store.count(there)) continue;
		dfs(there);
	}
}

void bfs(int here) {
	queue<int> q;
	store.insert(here);
	cout << here << " ";
	q.push(here);
	while(q.size()) {
		int x = q.front(); q.pop();
		for(int there : adj[x]) {
			if(store.count(there) == 0) {
				store.insert(there);
				q.push(there);
				cout << there << " ";
			}
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> v;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	
	for(int i = 0; i < 1004; i++) {
		if(adj[i].size() >= 2)
			sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(v); store.clear();
	cout << "\n";
	bfs(v); store.clear();
	cout << "\n";
	
	return 0;
}
