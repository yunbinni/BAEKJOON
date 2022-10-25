#include<bits/stdc++.h>
using namespace std;

int d[4][2]={ {-1,0}, {0,1}, {1,0}, {0,-1} };

int N, M;
int inp[1004][1004], vis[1004][1004][2];

struct Pos {
	int r, c, brk;
	Pos(int p1, int p2, int p3) {
		r=p1; c=p2; brk=p3;
	}
};

int BFS() {
	queue<Pos> Q;
	vis[1][1][0]=1;
	Q.push(Pos(1, 1, 0));
	while(!Q.empty()) {
		int cr=Q.front().r;
		int cc=Q.front().c;
		int cbrk=Q.front().brk;
		Q.pop();
		if(cr==N && cc==M) return vis[cr][cc][cbrk];
		for(int i=0; i<4; i++) {
			int nr=cr+d[i][0];
			int nc=cc+d[i][1];
			if(nr>=1 && nc>=1 && nr<=N && nc<=M && vis[nr][nc][cbrk]==0) {
				if(inp[nr][nc]==0) {
					vis[nr][nc][cbrk]=vis[cr][cc][cbrk]+1;
					Q.push(Pos(nr, nc, cbrk));
				}
				if(inp[nr][nc]==1 && cbrk==0) {
					vis[nr][nc][1]=vis[cr][cc][cbrk]+1;
					Q.push(Pos(nr, nc, 1));
				}
			}
		}
	}
	return -1;
}

void input() {
	cin>>N>>M;
	for(int r=1; r<=N; r++)
		for(int c=1; c<=M; c++)
			scanf("%1d", &inp[r][c]);
}

int main() {
	input();
	cout<<BFS()<<"\n";
	return 0;
}
