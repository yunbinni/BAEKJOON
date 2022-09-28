#include<bits/stdc++.h>
using namespace std;

int d[5][2]={ {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1} };

int N;
int inp[104][104], mem[104][104], vis[104][104];

set<pair<int, int> > S[10001];

int res=10001;

void input() {
	cin>>N;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin>>inp[i][j];
}

bool go(int nr, int nc) {
	if(nr>=1 && nr<=N && nc>=1 && nc<=N)
		return true;
	return false;
}

void DFS(int r, int c, int num) {
	mem[r][c]=num;
	for(int i=1; i<=4; i++) {
		int nr=r+d[i][0];
		int nc=c+d[i][1];
		if(go(nr, nc)) {
			if(inp[nr][nc]==1 && mem[nr][nc]==0)
				DFS(nr, nc, num);
			if(inp[nr][nc]==0 && mem[nr][nc]==0)
				S[num].insert(make_pair(r, c));
		}
	}
}

void BFS(int num) {
	memset(vis, -1, sizeof vis);
	queue<pair<int, int> > Q;
	for(auto it=S[num].begin(); it!=S[num].end(); it++) {
		vis[(*it).first][(*it).second]=0;
		Q.push(make_pair((*it).first, (*it).second));
	}
	
	while(!Q.empty()) {
		int cr=Q.front().first;
		int cc=Q.front().second;
		Q.pop();
		for(int i=1; i<=4; i++) {
			int nr=cr+d[i][0];
			int nc=cc+d[i][1];
			if(go(nr, nc)) {
				if(vis[nr][nc]==-1) {
					vis[nr][nc]=vis[cr][cc]+1;
					Q.push(make_pair(nr, nc));
					if(inp[nr][nc]==1 && mem[nr][nc]!=num)
						res=min(res, vis[cr][cc]);
				}
			}
		}
	}
}

void solve() {
	int cnt=1;
	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			if(inp[r][c]==1 && mem[r][c]==0) {
				DFS(r, c, cnt);
				cnt++;
			}
		}
	}
	for(int i=1; i<cnt; i++) BFS(i);
}

void output() {
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
