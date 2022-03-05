#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a[26] = { 0, };
	string s;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
		a[s[i] - 97]++;
	
	for(int i = 0; i < 26; i++)
		cout << a[i] << ' ';
	
	return 0;
}
