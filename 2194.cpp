#include<bits/stdc++.h>
using namespace std;

int d[4][2]={ {-1,0}, {0,1}, {1,0}, {0,-1} };

int N, M, A, B, K, sr, sc, er, ec;
int grp[504][504], vis[504][504];

void input() {
	cin>>N>>M>>A>>B>>K;
	for(int i=0; i<K; i++) {
		int tr, tc;
		cin>>tr>>tc;
		grp[tr][tc]=1;
	}
	cin>>sr>>sc>>er>>ec;
}

bool go(int nr, int nc, int dir) {
	//up
	if(dir==0) {
		if(nr<1) return false;
		for(int ic=nc; ic<nc+B; ic++)
			if(grp[nr][ic]==1) return false;
		return true;
	}
	//ri
	if(dir==1) {
		if(nc+B-1>M) return false;
		for(int ir=nr; ir<nr+A; ir++)
			if(grp[ir][nc+B-1]==1) return false;
		return true;
	}
	//dw
	if(dir==2) {
		if(nr+A-1>N) return false;
		for(int ic=nc; ic<nc+B; ic++)
			if(grp[nr+A-1][ic]==1) return false;
		return true;
	}
	//le
	if(dir==3) {
		if(nc<1) return false;
		for(int ir=nr; ir<nr+A; ir++)
			if(grp[ir][nc]==1) return false;
		return true;
	}
	return false;
}

int BFS() {
	queue<pair<int, int> > Q;
	vis[sr][sc]=0;
	Q.push(make_pair(sr, sc));
	while(!Q.empty()) {
		int cr=Q.front().first;
		int cc=Q.front().second;
		Q.pop();
		if(cr==er && cc==ec) return vis[cr][cc];
		for(int i=0; i<4; i++) {
			int nr=cr+d[i][0];
			int nc=cc+d[i][1];
			if(go(nr, nc, i)) {
				if(vis[nr][nc]==-1) {
					vis[nr][nc]=vis[cr][cc]+1;
					Q.push(make_pair(nr, nc));
				}
			}
		}
	}
	return -1;
}

int main() {
	input();
	memset(vis, -1, sizeof vis);
	cout<<BFS()<<"\n";
	return 0;
}
