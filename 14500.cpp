#include<bits/stdc++.h>
using namespace std;

int n, m, res=0;
int a[504][504], chk[504][504];
int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};

int psum(int sy, int sx, int ey, int ex) {
	int sum=0;
	for(int i=sy; i<=ey; i++) {
	for(int j=sx; j<=ex; j++) {
		sum+=a[i][j];
	}}
	return sum;
}

void DFS(int L, int y, int x, int psum) {
	if(L>3) {
		if(psum>res) res=psum;
		return;
	}
	
	for(int i=0; i<4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<1 || nx<1 || ny>n || nx>m) continue;
		if(chk[ny][nx]==0) {
			chk[ny][nx]=1;
			DFS(L+1, ny, nx, psum+a[y][x]);
			chk[ny][nx]=0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		scanf("%d", &a[i][j]);
	}}
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		chk[i][j]=1;
		DFS(0, i, j, 0);
		chk[i][j]=0;
	}}
	//'で,ぬ,た,っ'
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		int psum1=psum(i, j, i+1, j+2);
		int psum2=psum(i, j, i+2, j+1);
		int sum1=psum1-(a[i][j]+a[i][j+2]);
		int sum2=psum1-(a[i+1][j]+a[i+1][j+2]);
		int sum3=psum2-(a[i][j+1]+a[i+2][j+1]);
		int sum4=psum2-(a[i][j]+a[i+2][j]);
		if(sum1>res) res=sum1;
		if(sum2>res) res=sum2;
		if(sum3>res) res=sum3;
		if(sum4>res) res=sum4;
	}}
	printf("%d\n", res);
	return 0;
}
