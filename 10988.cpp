#include <iostream>
using namespace std;

int f(string s) {
	for(int i = 0; i < s.size()/2; i++) {
		if(s[i] != s[s.size() - 1 - i])
			return 0;
	}
	
	return 1;
}

int main() {
	string s;
	cin >> s;
	
	cout << f(s);
	
	return 0;
}
