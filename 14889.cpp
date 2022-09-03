#include<bits/stdc++.h>
using namespace std;

int n, res=INT_MAX;
int arr[24][24], chk[24];

void DFS(int L, int s) {
	if(L==n/2) {
		vector<int> A, B;
		for(int i=0; i<n; i++) {
			if(chk[i]==1) A.push_back(i);
			if(chk[i]==0) B.push_back(i);
		}
		int a=0, b=0;
		for(int i=0; i<A.size(); i++) {
			for(int j=0; j<A.size(); j++) {
				if(i==j) continue;
				a+=arr[A[i]][A[j]];
			}
		}
		for(int i=0; i<B.size(); i++) {
			for(int j=0; j<B.size(); j++) {
				if(i==j) continue;
				b+=arr[B[i]][B[j]];
			}
		}
		res=min(res, abs(a-b));
		return;
	}
	
	for(int i=s; i<n; i++) {
		chk[i]=1;
		DFS(L+1, i+1);
		chk[i]=0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>arr[i][j];
	DFS(0, 0);
	cout<<res;
	return 0;
}
