#include<bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool chk[304][304];

int n, m, pcs, res;
int inp[304][304];

void input() {
	cin>>n>>m;
	for(int y=1; y<=n; y++) for(int x=1; x<=m; x++) cin>>inp[y][x];
}

void todo() {
	int tmp[304][304];
	memcpy(tmp, inp, sizeof inp);
	for(int y=1; y<=n; y++) {
		for(int x=1; x<=m; x++) {
			if(tmp[y][x]) {
				int cnt=0;
				for(int k=0; k<4; k++) {
					int ny=y+dy[k];
					int nx=x+dx[k];
					if(tmp[ny][nx]==0) cnt++;
				}
				if(inp[y][x]>cnt) inp[y][x]-=cnt;
				else inp[y][x]=0;
			}
		}
	}
}

void BFS(int y, int x) {
	queue<pair<int, int> > Q;
	chk[y][x]=true;
	Q.push(make_pair(y, x));
	while(!Q.empty()) {
		int cury=Q.front().first;
		int curx=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++) {
			int ny=cury+dy[i];
			int nx=curx+dx[i];
			if(ny>=1 && nx>=1 && ny<=n && nx<=m && !chk[ny][nx] && inp[ny][nx]) {
				chk[ny][nx]=true;
				Q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	while(1) {
		memset(chk, false, sizeof chk);
		pcs=0;
		for(int y=1; y<=n; y++) {
			for(int x=1; x<=m; x++) {
				if(!chk[y][x] && inp[y][x]) {
					pcs++;
					BFS(y, x);
				}
			}
		}
		if(pcs>=2) {cout<<res; break;}
		if(pcs==0) {cout<<0; break;}
		todo();
		res++;
	}
	return 0;
}
