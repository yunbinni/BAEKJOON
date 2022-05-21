#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, m, res;
string n_str;
int brk[10];

bool check(int now) {
	string s=to_string(now);
	for(int i=0; i<s.length(); i++) {
		if(brk[s[i]-48]==1) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	int tmp;
	for(int i=0; i<m; i++) {
		cin>>tmp;
		brk[tmp]=1;
	}
	n_str=to_string(n);
	res=abs(n-100);
	for(int i=0; i<=1000000; i++) {
		if(check(i)) {
			int tmp=abs(n-i)+to_string(i).length();
			res=min(tmp, res);
		}
	}
	cout<<res<<"\n";
	return 0;
}
