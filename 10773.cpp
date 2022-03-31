#include <iostream>
#include <stack>
using namespace std;

int k, ret;
stack<int> stk;

int main() {
	cin >> k;
	int temp;
	for(int i = 0; i < k; i++) {
		cin >> temp;
		if(stk.size() && temp==0) stk.pop();
		else stk.push(temp);
	}
	
	while(stk.size()) {
		ret += stk.top();
		stk.pop();
	}
	
	cout << ret << "\n";
	
	return 0;
}
