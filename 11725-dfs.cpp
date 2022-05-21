#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;

int parent[MAX+1], visited[MAX+1];
vector<int> map[MAX+1];

void bfs(int nodeNum) {
	visited[nodeNum]=1;
	
	for(int e : map[nodeNum]) {
		if(visited[e]!=1) {
			parent[e]=nodeNum;
			dfs(e);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n-1; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		
		map[node1].push_back(node2);
		map[node2].push_back(node1);
	}
	
	dfs(1);
	
	for(int i=2; i<=n; i++) printf("%d\n", parent[i]);
	
	return 0;
}
