#include<bits/stdc++.h>
using namespace std;

string in;

void input();
string solve();

int main() {
	input();
	cout<<solve();
	return 0;
}

void input() {
	getline(cin, in);
}

string solve() {
	string store;
	string result;
	
	in += ' ';
	
	for(char c : in) {
		
		if(c=='<') {
			reverse(store.begin(), store.end());
			result += store;
			store.clear();
			store += '<';
		}
		
		else if(c=='>') {
			store += '>';
			result += store;
			store.clear();
		}
		
		else if(c==' ') {
			if(store[0]=='<') store += ' ';
			else {
				reverse(store.begin(), store.end());
				store += ' ';
				result += store;
				store.clear();
			}
		}
		
		else store += c;
	}
	
	return result;
}
