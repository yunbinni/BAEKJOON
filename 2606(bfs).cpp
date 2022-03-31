#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, net, in1, in2, ret;

bool vis[104];
vector<int> adj[104];

void bfs(int here) {
	queue<int> q;
	vis[here] = 1;
	q.push(here);
	while(q.size()) {
		int here = q.front(); q.pop(); ret++;
		if(adj[here].size()) {
			for(int there : adj[here]) {
				if(!vis[there]) {
					vis[there] = 1;
					q.push(there);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> net;
	for(int i = 0; i < net; i++) {
		cin >> in1 >> in2;
		adj[in1].push_back(in2); adj[in2].push_back(in1);
	}
	
	bfs(1);
	
	cout << ret - 1 << "\n";
	
	return 0;
}
