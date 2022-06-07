#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	deque<int> dQ;
	int n;
	cin>>n;
	while(n--) {
		string s;
		cin>>s;
		if(s=="push_front") {
			int n;
			cin>>n;
			dQ.push_front(n);
		}
		if(s=="push_back") {
			int n;
			cin>>n;
			dQ.push_back(n);
		}
		if(s=="pop_front") {
			if(dQ.empty()) cout<<"-1\n";
			else {
				cout<<dQ.front()<<"\n";
				dQ.pop_front();
			}
		}
		if(s=="pop_back") {
			if(dQ.empty()) cout<<"-1\n";
			else {
				cout<<dQ.back()<<"\n";
				dQ.pop_back();
			}
		}
		if(s=="size") cout<<dQ.size()<<"\n";
		if(s=="empty") {
			if(dQ.empty()) cout<<"1\n";
			else cout<<"0\n";
		}
		if(s=="front") {
			if(dQ.empty()) cout<<"-1\n";
			else cout<<dQ.front()<<"\n";
		}
		if(s=="back") {
			if(dQ.empty()) cout<<"-1\n";
			else cout<<dQ.back()<<"\n";
		}
	}
	return 0;
}
