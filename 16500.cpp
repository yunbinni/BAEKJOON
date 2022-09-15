#include<bits/stdc++.h>
using namespace std;

string S;
int n;
vector<string> A;

bool dp[101];

void input() {
	cin>>S>>n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
}

void solve() {
	dp[S.length()]=true;
	
	for(int i=S.length()-1; i>=0; i--) {
		for(int j=0; j<n; j++) {
			if(S.find(A[j], i)==i && dp[i+A[j].length()]==true) {
				dp[i]=true;
				break;
			} else {
				dp[i]=false;
			}
		}
	}
}

void output() {
	cout<<dp[0]<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}
