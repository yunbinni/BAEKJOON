#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, res=0, zi; //zero index
	cin>>n>>m;
	vector<int> pos(n+1, 0);
	for(int i=0; i<n; i++) cin>>pos[i];
	sort(pos.begin(), pos.end());
	for(int i=0; i<=n; i++) if(pos[i]==0) {zi=i; break;}
	for(int i=0; i<zi; i+=m) res+=abs(pos[i]*2); //음수영역 
	for(int i=n; i>zi; i-=m) res+=pos[i]*2;		 //양수영역
	res-=max(abs(pos[0]), abs(pos[n]));			 //최대거리를 마지막으로 간 것처럼 처리
	cout<<res;
	return 0;
}
