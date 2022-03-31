#include <iostream>
#include <stack>
using namespace std;

int n, flag;
string s;
stack<char> _stack;

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	while(n--)
	{
		cin >> s;
		flag = 0;
		while(_stack.size()) {_stack.pop();}
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(')
				_stack.push(s[i]);
			else if(_stack.size() && s[i] == ')')
				_stack.pop();
			else if(_stack.size()==0 && s[i] == ')') {
				flag = 1;
				break;
			}
		}
		
		if(_stack.size() || flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	return 0;
}
