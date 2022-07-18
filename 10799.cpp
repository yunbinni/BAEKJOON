#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int res=0, laser=0;
	string inp;
	stack<char> stk;
	cin>>inp;
	for(int i=0; i<inp.size(); i++) {
		if(inp[i]=='(') stk.push('(');
		else {
			stk.pop();
			if(inp[i-1]=='(') res+=stk.size();
			else res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
