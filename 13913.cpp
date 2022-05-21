#include<bits/stdc++.h>
using namespace std;

const int maxN=100000;
int n, k, cur, par;
int cnt[maxN+1], parArr[maxN+1];
vector<int> path;

void BFS() {
	queue<pair<int, int> > Q;
	cnt[n]=0;
	Q.push({n, 0});
	while(!Q.empty()) {
		cur=Q.front().first;
		par=Q.front().second;
		Q.pop();
		
		if(cur==k) {
			cout<<cnt[k]<<"\n";
			path.push_back(cur);
			while(cur!=n) {
				par=parArr[cur];
				cur=par;
				path.push_back(par);
			}
			for(int i=path.size()-1; i>=0; i--) cout<<path[i]<<" ";
			cout<<"\n";
			break;
		}
		if(cur-1>=0 && cnt[cur-1]==0) {
			cnt[cur-1]=cnt[cur]+1;
			parArr[cur-1]=cur;
			Q.push({cur-1, cur});
		}
		if(cur+1<=maxN && cnt[cur+1]==0) {
			cnt[cur+1]=cnt[cur]+1;
			parArr[cur+1]=cur;
			Q.push({cur+1, cur});
		}
		if(cur*2<=maxN && cnt[cur*2]==0) {
			cnt[cur*2]=cnt[cur]+1;
			parArr[cur*2]=cur;
			Q.push({cur*2, cur});
		}
	}
}

int main() {
	cin>>n>>k;
	BFS();
	return 0;
}
