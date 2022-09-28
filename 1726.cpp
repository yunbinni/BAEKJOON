#include<bits/stdc++.h>
using namespace std;

struct R {
	int r, c, d, cnt;
};

int M, N, sr, sc, sd, er, ec, ed;
int inp[104][104], d[5][2]={ {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} };
bool vis[104][104][5];

R s, e;

void input() {
	cin>>M>>N;
	for(int i=1; i<=M; i++)
		for(int j=1; j<=N; j++)
			cin>>inp[i][j];
	cin>>s.r>>s.c>>s.d>>e.r>>e.c>>e.d;
}

bool go(queue<R>& Q, R next) {
	if(next.r>=1 && next.c>=1 && next.r<=M && next.c<=N && !inp[next.r][next.c]) {
		if(!vis[next.r][next.c][next.d]) {
			vis[next.r][next.c][next.d]=true;
			Q.push(next);
		}
		return true;
	}
	return false;
}

int BFS() {
	queue<R> Q;
	vis[s.r][s.c][s.d]=true;
	Q.push(s);
	
	while(!Q.empty()) {
		R cur=Q.front();
		Q.pop();
		
		if(cur.r==e.r && cur.c==e.c && cur.d==e.d)
			return cur.cnt;
		
		// 명령1 
		for(int i=1; i<=3; i++) {
			R next={ cur.r+d[cur.d][0]*i, cur.c+d[cur.d][1]*i, cur.d, cur.cnt+1};
			if(!go(Q, next)) break;
		}
		
		// 명령2
		R next=cur;
		next.cnt++;
		
		if(next.d<=2) {
			for(int nd=3; nd<=4; nd++) {
				next.d=nd;
				go(Q, next);
			}
		}
		else {
			for(int nd=1; nd<=2; nd++) {
				next.d=nd;
				go(Q, next);
			}
		}
	}
	return 0;
}

int main() {
	input();
	cout<<BFS()<<"\n";
	return 0;
}
