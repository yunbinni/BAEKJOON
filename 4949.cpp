#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	while(true)
	{
		string s;
		getline(cin, s);
		if(s == ".") break;
		stack<int> _stack;
		int flag = 0;
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(' || s[i] == '[')
				_stack.push(s[i]);
			else if(s[i] == ')') {
				if(_stack.size() == 0 || _stack.top() == '[') {flag=1; break;}
				else _stack.pop();
			}
			else if(s[i] == ']') {
				if(_stack.size() == 0 || _stack.top() == '(') {flag=1; break;}
				else _stack.pop();
			}
		}
		
		if(_stack.size() == 0 && flag == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}
