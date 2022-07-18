#include<bits/stdc++.h>
using namespace std;

int n, res;
int arr[1004], dp[1004];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) {
		dp[i]=1;
		for(int j=1; j<i; j++) {
			if(arr[j]<arr[i])
				dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	cout<<res<<"\n";
	return 0;
}
