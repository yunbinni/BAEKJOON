#include<bits/stdc++.h>
using namespace std;

int N, sum, sum_2;

int main() {
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; i++) {
		int in;
		cin>>in;
		sum+=in;
		sum_2+=(in/2);
	}
	if(sum%3==0) {
		if(sum_2>=(sum/3)) {
			cout<<"YES\n";
			return 0;
		}
		else {
			cout<<"NO\n";
			return 0;
		}
	}
	else cout<<"NO\n";
	return 0;
}
