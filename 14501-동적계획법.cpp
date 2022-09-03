#include<bits/stdc++.h>
using namespace std;

int DP[20];
int T[20], P[20];

int main() {
	int N;
	cin>>N;
	for(int i=1; i<=N; i++) cin>>T[i]>>P[i];
	for(int i=N; i>=1; i--) {
		if(i+T[i]<=N+1) DP[i]=max(DP[i+1], P[i]+DP[i+T[i]]);
		else DP[i]=DP[i+1];
	}
	cout<<DP[1]<<"\n";
	return 0;
}
