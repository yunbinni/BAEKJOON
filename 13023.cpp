#include<iostream>
#include<vector>
using namespace std;

int res=0;
int chk[2004];
vector<int> arr[2004];

void DFS(int v, int L) {
	if(res>0) return;
	if(L>=4) {
		res=1;
		return;
	}
	for(int i=0; i<arr[v].size(); i++) {
		if(res>0) return;
		if(chk[arr[v][i]]==0) {
			chk[arr[v][i]]=1;
			DFS(arr[v][i], L+1);
			chk[arr[v][i]]=0;
		}
	}
}

int main() {
	int n, m, a, b;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int i=0; i<m; i++) {
		chk[i]=1;
		DFS(i, 0);
		chk[i]=0;
	}
	cout<<res<<"\n";
	return 0;
}
