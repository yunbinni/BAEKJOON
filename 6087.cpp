#include<bits/stdc++.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

struct Info {
	int r, c, cnt;
};

int W, H;
char inp[104][104];
int vis[104][104];

int idx=0;
Info arr[2];

void init() {
	memset(vis, -1, sizeof vis);
}

void input() {
	cin>>W>>H;
	for(int i=1; i<=H; i++) {
		for(int j=1; j<=W; j++) {
			cin>>inp[i][j];
			if(inp[i][j]=='C') {
				arr[idx].r=i, arr[idx].c=j, arr[idx].cnt=0;
				idx++;
				inp[i][j]='.';
			}
		}
	}
}

bool go(queue<Info>& Q, Info next) {
	if(next.r>=1 && next.r<=H && next.c>=1 && next.c<=W && inp[next.r][next.c]=='.') {
		if(vis[next.r][next.c]==-1) {
			vis[next.r][next.c]=next.cnt;
			Q.push(next);
		}
		return true;
	}
	return false;
}

void BFS() {
	queue<Info> Q;
	vis[arr[0].r][arr[0].c]=0;
	Q.push({arr[0].r, arr[0].c, 0});
	
	while(!Q.empty()) {
		Info cur=Q.front();
		Q.pop();
		
		for(int i=0; i<4; i++)
			for(int j=1; j<=104; j++)
				if(!go(Q, {cur.r+dy[i]*j, cur.c+dx[i]*j, cur.cnt+1})) break;
	}
}

void output() {
	cout<<vis[arr[1].r][arr[1].c]-1<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	init();
	input();
	BFS();
	output();
	return 0;
}
