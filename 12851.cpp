#include<bits/stdc++.h>
using namespace std;

const int maxN=100000;
int n, k, res1=INT_MAX, res2;
int vis[maxN+1];

void BFS() {
	queue<pair<int, int> > Q;
	Q.push(make_pair(n, 0));
	while(!Q.empty()) {
		int cur=Q.front().first;
		int time=Q.front().second;
		vis[cur]=1;
		Q.pop();
		
		if(time>res1) break;
		if(cur==k) {
			res1=time;
			res2++;
			continue;
		}
		
		if(cur-1>=0 && vis[cur-1]==0)
			Q.push(make_pair(cur-1, time+1));
		if(cur+1<=maxN && vis[cur+1]==0)
			Q.push(make_pair(cur+1, time+1));
		if(cur*2<=maxN && vis[cur*2]==0)
			Q.push(make_pair(cur*2, time+1));
	}
}

int main() {
	cin>>n>>k;
	BFS();
	cout<<res1<<"\n"<<res2<<"\n";
	return 0;
}
