#include<bits/stdc++.h>
using namespace std;

int N, M, A_i, B_i;
vector<vector<int> > inp;
vector<int> chk;

int res1, res2, res3;

void input() {
	cin>>N>>M;
	inp.assign(N+1, vector<int>(1, 0));
	chk.assign(N+1, -1);
	for(int i=1; i<=M; i++) {
		cin>>A_i>>B_i;
		inp[A_i].push_back(B_i);
		inp[B_i].push_back(A_i);
	}
}

void BFS(int s) {
	queue<int> Q;
	chk[s]=0;
	Q.push(s);
	while(!Q.empty()) {
		int cur=Q.front();
		Q.pop();
		for(int go : inp[cur]) {
			if(chk[go]==-1) {
				chk[go]=chk[cur]+1;
				Q.push(go);
			}
		}
	}
}

void output() {
	for(int v=N; v>=2; v--) {
		if(chk[v]>res2) {
			res1=v;
			res2=chk[v];
			res3=1;
		}
		else if(chk[v]==res2) {
			res1=v;
			res3++;
		}
	}
	cout<<res1<<" "<<res2<<" "<<res3<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	BFS(1);
	output();
	return 0;
}
