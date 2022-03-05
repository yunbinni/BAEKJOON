#include <bits/stdc++.h>
using namespace std;

int N;
string ori_s, pre, suf, s;

int main() {
	cin >> N;
	cin >> ori_s;
	
	int pos = ori_s.find('*');
	pre = ori_s.substr(0, pos);
	suf = ori_s.substr(pos + 1);
	
	for(int i = 0; i < N; i++) {
		cin >> s;
		
		if(pre.size() + suf.size() > s.size())
			cout << "NE\n";
		
		else {
			if (pre == s.substr(0, pre.size())
				&&
				suf == s.substr(s.size() - suf.size())
			)
				cout << "DA\n";
			
			else
				cout << "NE\n";
		}
	}
	
	return 0;
}
