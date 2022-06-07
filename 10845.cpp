#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> Q;
	int n;
	cin>>n;
	while(n--) {
		string s;
		cin>>s;
		if(s=="push") {
			int in;
			cin>>in;
			Q.push(in);
		}
		if(s=="pop") {
			if(Q.empty()) cout<<"-1\n";
			else {
				cout<<Q.front()<<"\n";
				Q.pop();
			}
		}
		if(s=="size") cout<<Q.size()<<"\n";
		if(s=="empty") {
			if(Q.empty()) cout<<"1\n";
			else cout<<"0\n";
		}
		if(s=="front") {
			if(Q.empty()) cout<<"-1\n";
			else cout<<Q.front()<<"\n";
		}
		if(s=="back") {
			if(Q.empty()) cout<<"-1\n";
			else cout<<Q.back()<<"\n";
		}
	}
	return 0;
}
