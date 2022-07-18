#include <iostream>
#include <vector>
using namespace std;

int n, net, in1, in2, ret;

bool vis[104];
vector<int> adj[104];

void dfs(int here) {
	vis[here] = 1;
	ret++;
	for(int there : adj[here]) {
		if(vis[there] == 0) dfs(there);
	}
}

int main() {
	cin >> n;
	cin >> net;
	for(int i = 0; i < net; i++) {
		cin >> in1 >> in2;
		adj[in1].push_back(in2); adj[in2].push_back(in1);
	}
	
	dfs(1);
	
	cout << ret - 1 << "\n";
	
	return 0;
}
