#include <iostream>
#include <stack>
using namespace std;

int N, ret;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	while(N--)
	{
		cin >> s;
		stack<char> stk;
		
		for(char a : s) {
			if(stk.size() && stk.top() == a) stk.pop();
			else stk.push(a);
		}
		
		if(stk.size() == 0) ret++;
		
	}
	
	cout << ret << "\n";
	
	return 0;
}
