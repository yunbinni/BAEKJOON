#include<bits/stdc++.h>
using namespace std;

int r, c, res=1;
char arr[24][24];
int chk[26];

int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};

void DFS(int y, int x, int L) {
	res=max(res, L);
	for(int i=0; i<4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny>=1 && ny<=r && nx>=1 && nx<=c && chk[arr[ny][nx]-65]==0) {
			chk[arr[ny][nx]-65]=1;
			DFS(ny, nx, L+1);
			chk[arr[ny][nx]-65]=0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>r>>c;
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			cin>>arr[i][j];
		}
	}
	chk[arr[1][1]-65]=1;
	DFS(1, 1, 1);
	cout<<res<<"\n";
	return 0;
}
