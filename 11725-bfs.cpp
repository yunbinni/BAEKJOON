#include<iostream>
#include<vector>
#include<queue>
#define MAX 100000
using namespace std;

int parent[MAX+1], visited[MAX+1];
vector<int> map[MAX+1];

void bfs() {
	queue<int> q; q.push(1);
	visited[1]=1;
	
	while(q.size()) {
		//insert
		int x=q.front(); q.pop();
		
		for(int e : map[x]) {
			if(visited[e]==0) {
				visited[e]=1;
				parent[e]=x;
				q.push(e);
			}
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
	
	bfs();
	
	for(int i=2; i<=n; i++) printf("%d\n", parent[i]);
	
	return 0;
}
