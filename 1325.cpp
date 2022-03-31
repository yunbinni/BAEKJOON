#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

// visited ¹è¿­ »ðÀÔ 
int n, m, a, b, visited[10004], maxN = INT_MIN;
vector<int> v[10004];
int arr[10004];

int dfs(int here) {
	visited[here] = 1;
	int ret = 0;
	if(v[here].size()==0) return 0;
	for(int there : v[here]) {
		if(visited[there]) continue;
		ret++;
		ret += dfs(there);
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		arr[i] = dfs(i);
		maxN = max(maxN, arr[i]);
	}
	
	for(int i = 1; i <= n; i++) {
		if(arr[i] == maxN) cout << i << ' ';
	}
	
	return 0;
}
