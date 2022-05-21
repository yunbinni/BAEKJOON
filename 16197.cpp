#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, res=INT_MAX;
char arr[24][24];
int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};

typedef struct _coin {
	int y; int x;
	_coin(int a, int b) {
		y=a; x=b;
	}
} C;

bool isIn(C c) {
	if(c.y>=1 && c.y<=n && c.x>=1 && c.x<=m)
		return true;
	return false;
}

int count(C c1, C c2) {
	if(isIn(c1) && isIn(c2)) return 2;
	if(!isIn(c1) && !isIn(c2)) return 0;
	return 1;
}

void DFS(int L, C c1, C c2) {
	if(L>10 || count(c1, c2)==0) return;
	
	if(count(c1, c2)==1) {
		if(L<res) {
			res=L;
			return;
		}
	}
	for(int i=0; i<4; i++) {
		bool t1=false, t2=false;
		if(arr[c1.y+dy[i]][c1.x+dx[i]]!='#') {
			c1.y+=dy[i];
			c1.x+=dx[i];
			t1=true;
		}
		if(arr[c2.y+dy[i]][c2.x+dx[i]]!='#') {
			c2.y+=dy[i];
			c2.x+=dx[i];
			t2=true;
		}
		DFS(L+1, c1, c2);
		if(t1==true) {
			c1.y-=dy[i];
			c1.x-=dx[i];
		}
		if(t2==true) {
			c2.y-=dy[i];
			c2.x-=dx[i];
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<C> Cs;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		cin>>arr[i][j];
		if(arr[i][j]=='o') {
			Cs.push_back(C(i, j));
			arr[i][j]='.';
		}
	}}
	DFS(0, Cs[0], Cs[1]);
	if(res==INT_MAX) cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
