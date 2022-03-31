#include <iostream>
#include <vector>
using namespace std;

int n, p, d, root, ret;
vector<int> adj[54];

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for(int there : adj[here]) {
		if(there == d) continue;
		ret += dfs(there);
		child++;
	}
	
	if(child == 0) return 1;
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
    cin >> n;
    
	for(int i = 0; i < n; i++) {
		cin >> p;
		if(p == -1) root = i;
		else adj[p].push_back(i);
	}
	
	cin >> d;
	if(d == root) {
		cout << 0 << "\n";
		return 0;
	}
	
	cout << dfs(root) << "\n";
	
	return 0;
}
