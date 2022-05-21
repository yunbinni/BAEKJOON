#include<bits/stdc++.h>
using namespace std;

int n, in;
int chk[20*100001];
vector<int> S;

void DFS(int L, int sum) {
	if(L==n) {
		chk[sum]=1;
		return;
	}
	DFS(L+1, sum);
	DFS(L+1, sum+S[L+1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	S.push_back(0);
	for(int i=0; i<n; i++) {
		cin>>in;
		S.push_back(in);
	}
	DFS(0, 0);
	int idx=1;
	while(chk[idx]==1) idx++;
	printf("%d\n", idx);
	return 0;
}
