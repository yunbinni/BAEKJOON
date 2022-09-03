#include<bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool chk[304][304];

int n, m, pcs, res;
int inp[304][304];

void input() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>inp[i][j];
}

void todo() {
	int tmp[304][304];
	memcpy(tmp, inp, sizeof tmp);
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

void DFS(int y, int x) {
	chk[y][x]=true;
	for(int i=0; i<4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny>=1 && nx>=1 && ny<=n && nx<=m && !chk[ny][nx] && inp[ny][nx])
			DFS(ny, nx);
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
					DFS(y, x);
				}
			}
		}
		if(pcs==0) {cout<<0; break;}
		if(pcs>=2) {cout<<res; break;}
		todo();
		res++;
	}
	return 0;
}
