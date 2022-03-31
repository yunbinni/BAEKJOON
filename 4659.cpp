#include <iostream>
#include <set>
using namespace std;

string str;
set<char> v_set = {'a', 'e', 'i', 'o', 'u'};

bool oper(string s) {
	int vowel = 0;
	
	for(char c : s)
		if(v_set.count(c)) vowel++;
	
	if(s.size() > 2) {
		for(int i = 0; i < s.size() - 2; i++) {
			if(v_set.count(s[i]) && v_set.count(s[i+1]) && v_set.count(s[i+2]))
				return false;
				
			if(v_set.count(s[i]) == 0 && v_set.count(s[i+1]) == 0 && v_set.count(s[i+2]) == 0)
				return false;
		}
	}
	
	if(s.size() > 2) {
		for(int i = 0; i < s.size() - 1; i++) {
			if(s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
				return false;
		}
	}
	
	if(vowel) return true;
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true) {
		cin >> str;
		if(str == "end") break;
		
		if(oper(str))
			cout << "<" << str << "> " << "is " << "acceptable.\n";
		else
			cout << "<" << str << "> " << "is not " << "acceptable.\n";
	}
	
	return 0;
}
