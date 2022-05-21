#include<bits/stdc++.h>
using namespace std;

int n, m, r, c, d, res=INT_MIN;
int arr[54][54], chk[54][54];
int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};

void DFS(int y, int x, int dir, int L) {
	if(L>res) res=L;
	bool flag=false;
	chk[y][x]=1;
	for(int i=0; i<4; i++) {
		dir--; if(dir<0) dir=3; //회전 
		int ny=y+dy[dir]; //전진 
		int nx=x+dx[dir];
		if(ny<=0 || nx<=0 || ny>=n-1 || nx>=m-1) continue; //경계라면 skip 
		if(chk[ny][nx]==0 && arr[ny][nx]==0) {
			DFS(ny, nx, dir, L+1);
			chk[ny][nx]=0;
			flag=true;
			break;
		}
	}
	//4방향모두 돌았을때
	if(flag==false) {
		int ny=y-dy[dir]; //후진 
		int nx=x-dx[dir];
		if(arr[ny][nx]==1) return;
		else DFS(ny, nx, dir, L);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>r>>c>>d;
	for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
		cin>>arr[i][j];
	}}
	DFS(r, c, d, 1);
	cout<<res<<"\n";
	return 0;
}
