#include<bits/stdc++.h>
using namespace std;

string solve(string in);

int main() {
	int T;
	string in;
	
	cin>>T;
	cin.ignore(); // remove \n
	
	for(int i=0; i<T; i++) {
		getline(cin, in);
		cout<<solve(in)<<"\n";
	}
	
	return 0;
}

string solve(string in) {
	string store="";
	string result="";
	
	for(char c : in) {
		
		if(c==' ') {
			reverse(store.begin(), store.end());
			result += (store + " ");
			store.clear();
		}
		else store.push_back(c);
	}
	
	reverse(store.begin(), store.end());
	result += store;
	
	return result;
}
