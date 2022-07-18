#include<bits/stdc++.h>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1}; 

int arr[104][104];

int n, m, k;
int sx, sy, ex, ey;

int area; //¿µ¿ª ³ÐÀÌ

void BFS(int y, int x); 

int res1;
vector<int> res2;

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
            BFS(i, j);
            res1++;
            res2.push_back(area);
            area=0;
        }
    }}
}

void BFS(int y, int x) {
	queue<pair<int, int> > Q;
	
	arr[y][x]=1;
	area++;
	Q.push(make_pair(y, x));
	
	while(!Q.empty()) {
		int curY=Q.front().first;
		int curX=Q.front().second;
		Q.pop();
		
		for(int i=0; i<4; i++) {
			int ny=curY+dy[i];
			int nx=curX+dx[i];
			
			if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
			
			if(arr[ny][nx]==0) {
				arr[ny][nx]=1;
				area++;
				Q.push(make_pair(ny, nx));
			}
		}
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
