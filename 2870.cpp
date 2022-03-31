#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
string s, num;
vector<string> v;

bool cmp(string a, string b) {
	if(a.size() == b.size())
		return a < b; //사전순 비교 
	return a.size() < b.size();
}

void go() {
	if(num.size()) {
		while(true) {
			if(num.size() && num.front() == '0') num.erase(num.begin());
			else break;
		}
		if(num.size() == 0) num = "0"; //다 지웠을때 처리 
		v.push_back(num);
		num = "";
	}
}

int main() {
	cin >> n;
	
	while(n--)
	{
		cin >> s;
		num = "";
		
		for(int i = 0; i < s.size(); i++) {
			if(48 <= s[i] && s[i] <= 57)
				num += s[i];
			else
				go();
		}
		go();
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(string a : v) {
		cout << a << "\n";
	}
	
	return 0;
}
