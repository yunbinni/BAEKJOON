#include<bits/stdc++.h>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1}; 

int arr[104][104];

int n, m, k;
int sx, sy, ex, ey;

int area; // ¿µ¿ª³ÐÀÌ

int res1;
vector<int> res2;

void DFS(int y, int x);

void input() {
	cin>>n>>m>>k;
	while(k--) {
		cin>>sx>>sy>>ex>>ey;
		for(int i=sy; i<ey; i++) {
		for(int j=sx; j<ex; j++) {
			arr[i][j]=1;
		}}
	}
}

void solution() {
	for(int i=0; i<n; i++) {
	for(int j=0; j<m; j++) {
		if(arr[i][j]==0) {
			DFS(i, j);
			res1++;
			res2.push_back(area);
			area=0;
		}
	}}
}

void DFS(int y, int x) {
	arr[y][x]=1;
	area++;
	for(int i=0; i<4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
		
		if(arr[ny][nx]==0) DFS(ny, nx);
	}
}

void output() {
	cout<<res1<<"\n";
	sort(res2.begin(), res2.end());
	for(int i=0; i<res1; i++) cout<<res2[i]<<" ";
	cout<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	solution();
	output();
	return 0;
}
