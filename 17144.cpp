#include<bits/stdc++.h>
using namespace std;

int d[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};

int R, C, T, res;
int A[54][54], B[54][54];

pair<int, int> coord[2];

void dw(int c, int u, int d) {
	for(int r=d; r>=u; r--) {
		if(A[r+1][c]!=-1) A[r+1][c]=A[r][c];
	}
	A[u][c]=0;
}

void le(int row, int l, int r) {
	for(int c=l; c<=r; c++) {
		A[row][c-1]=A[row][c];
	}
	A[row][r]=0;
}

void up(int c, int u, int d) {
	for(int r=u; r<=d; r++) {
		if(A[r-1][c]!=-1) A[r-1][c]=A[r][c];
	}
	A[d][c]=0;
}

void ri(int row, int l, int r) {
	for(int c=r; c>=l; c--) {
		A[row][c+1]=A[row][c];
	}
	A[row][l]=0;
}

void input() {
	cin>>R>>C>>T;
	int tmp=0;
	for(int r=1; r<=R; r++) {
		for(int c=1; c<=C; c++) {
			cin>>A[r][c];
			if(A[r][c]==-1) {
				coord[tmp].first=r;
				coord[tmp++].second=c;
			}
		}
	}
}

void action1() {
	memset(B, 0, sizeof B);
	for(int r=1; r<=R; r++) {
		for(int c=1; c<=C; c++) {
			if(A[r][c]>0) {
				int cnt=0;
				for(int i=0; i<4; i++) {
					int nr=r+d[i][0];
					int nc=c+d[i][1];
					if(nr<1 || nc<1 || nr>R || nc>C || A[nr][nc]==-1) continue;
					B[nr][nc]+=(A[r][c]/5);
					cnt++;
				}
				A[r][c]-=(A[r][c]/5)*cnt;
			}
		}
	}
	for(int r=1; r<=R; r++) {
		for(int c=1; c<=C; c++) {
			A[r][c]+=B[r][c];
		}
	}
}

void action2() {
	dw(1, 1, coord[0].first-1);
	le(1, 2, C);
	up(C, 2, coord[0].first);
	ri(coord[0].first, 2, C-1);
	
	up(1, coord[1].first+1, R);
	le(R, 2, C);
	dw(C, coord[1].first, R-1);
	ri(coord[1].first, 2, C-1);
}

void solve() {
	while(T--) {
		action1();
		action2();
	}
	for(int r=1; r<=R; r++) {
		for(int c=1; c<=C; c++) {
			if(A[r][c]>0) res+=A[r][c];
		}
	}
}

void output() {
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
