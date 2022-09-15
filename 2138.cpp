#include<bits/stdc++.h>
using namespace std;

int n, cnt, res=100001;
string inp, dest, tmp;

void input() {
	cin>>n>>inp>>dest;
}

void action(int idx) {
	if(idx>0) tmp[idx-1]=(tmp[idx-1]=='0')?'1':'0';
	tmp[idx]=(tmp[idx]=='0')?'1':'0';
	if(idx<n-1) tmp[idx+1]=(tmp[idx+1]=='0')?'1':'0';
	cnt++;
}

void solve(int s) {
	tmp=inp;
	cnt=0;
	if(s==0) action(0);
	for(int i=1; i<n; i++) {
		if(tmp[i-1]!=dest[i-1]) action(i);
	}
	if(tmp==dest) res=min(res, cnt);
}

int main(){
	ios_base::sync_with_stdio(0);
	input();
	solve(0);
	solve(1);
	if(res==100001) cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
