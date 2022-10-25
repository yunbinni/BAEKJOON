#include<bits/stdc++.h>
using namespace std;

string my_string;
int M;

list<char> store;
list<char>::iterator cursorIndex;

void input();
void solve();
void output();

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	output();
	return 0;
}

void input() {
	getline(cin, my_string);
	cin>>M;
	cin.ignore();
	store.assign(my_string.begin(), my_string.end());
	cursorIndex = store.end();
}

void solve() {
	
	while(M--) {
		string order;
		getline(cin, order);
		
		if(order=="L")
			if(cursorIndex!=store.begin())
				cursorIndex--;
		
		if(order=="D")
			if(cursorIndex!=store.end())
				cursorIndex++;
		
		if(order=="B")
			if(cursorIndex!=store.begin())
				cursorIndex=store.erase(--cursorIndex);
		
		if(order[0]=='P') {
			store.insert(cursorIndex, order[2]);
		}
	}
	
}

void output() {
	for(auto it=store.begin(); it!=store.end(); it++)
		cout<<*it;
}
