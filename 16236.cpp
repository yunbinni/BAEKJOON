#include<bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int n;
int grp[24][24], chk[24][24];

pair<int, int> pos;
int sz=2, cnt;

pair<int, int> trg;
int rng;

int res;

void input() {
	cin>>n;
	for(int y=1; y<=n; y++) {
		for(int x=1; x<=n; x++) {
			cin>>grp[y][x];
			if(grp[y][x]==9) {
				pos.first=y;
				pos.second=x;
				grp[y][x]=0;
			}
		}
	}
}

void BFS(int y, int x) {
	memset(chk, -1, sizeof chk);
	trg.first=24, trg.second=24, rng=401;
	chk[y][x]=0;
	queue<pair<int, int> > Q;
	Q.push(make_pair(y, x));
	while(!Q.empty()) {
		int cy=Q.front().first;
		int cx=Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++) {
			int ny=cy+dy[i];
			int nx=cx+dx[i];
			if(ny>=1 && nx>=1 && ny<=n && nx<=n && chk[ny][nx]==-1 && grp[ny][nx]<=sz) {
				chk[ny][nx]=chk[cy][cx]+1;
				if(grp[ny][nx]>0 && grp[ny][nx]<sz) {
					if(chk[ny][nx]<rng) {
						trg.first=ny;
						trg.second=nx;
						rng=chk[ny][nx];
					}
					if(chk[ny][nx]==rng) {
						if(ny<trg.first) {
							trg.first=ny;
							trg.second=nx;
						}
						if(ny==trg.first) {
							if(nx<trg.second) {
								trg.first=ny;
								trg.second=nx;
							}
						}
					}
				}
				Q.push(make_pair(ny, nx));
			}
		}
	}
}

void output() {
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	while(true) {
		BFS(pos.first, pos.second);
		if(trg.first==24 && trg.second==24) break;
		else {
			pos.first=trg.first, pos.second=trg.second;
			grp[pos.first][pos.second]=0;
			cnt++;
			if(cnt==sz) sz++, cnt=0;
			res+=chk[pos.first][pos.second];
		}
	}
	output();
	return 0;
}
