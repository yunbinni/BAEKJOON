#include<bits/stdc++.h>
using namespace std;

int T, I, sy, sx, ey, ex;
int graph[304][304];
int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8]={-2, -1, 1, 2, -2, -1, 1, 2};

queue<pair<int, int> > Q;

void BFS() {
	graph[sy][sx]=0;
	Q.push({sy, sx});
	while(!Q.empty()) {
		int y=Q.front().first;
		int x=Q.front().second;
		Q.pop();
		for(int i=0; i<8; i++) {
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0 || nx<0 || ny>=I || nx>=I) continue;
			if(graph[ny][nx]==-1) {
				graph[ny][nx]=graph[y][x]+1;
				Q.push({ny, nx});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) {
		memset(graph, -1, sizeof graph);
		cin>>I>>sy>>sx>>ey>>ex;
		BFS();
		cout<<graph[ey][ex]<<"\n";
	}
	return 0;
}
