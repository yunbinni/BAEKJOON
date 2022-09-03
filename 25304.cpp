#include<bits/stdc++.h>
using namespace std;

int main() {
	int x, n, a, b, sum=0;
	cin>>x>>n;
	while(n--) {
		cin>>a>>b;
		sum+=a*b;
	}
	if(x==sum) cout<<"Yes";
	else cout<<"No";
	return 0;
}
