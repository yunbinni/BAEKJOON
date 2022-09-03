#include<bits/stdc++.h>
using namespace std;

int n, res=0;
int col[15];

bool check(int L) {
	for(int i=0; i<L; i++)
		if(col[L]==col[i] || L-i==abs(col[L]-col[i]))
			return false;
	return true;
}

void DFS(int L) {
	if(L==n) {
		res++;
		return;
	}
	
	for(int i=0; i<n; i++) {
		col[L]=i;
		if(check(L)) DFS(L+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	DFS(0);
	cout<<res;
	return 0;
}
