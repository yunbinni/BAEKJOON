#include<bits/stdc++.h>
using namespace std;

const int maxN=100001;

int arr[maxN];
string res;

void solve(int n);

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	solve(n);
	
	return 0;
}

void solve(int n) {
	int idx=1;
	stack<int> Stack;

	for(int i=1; i<=n; i++) {
		if(Stack.empty() || Stack.top()!=arr[idx]) {
			res.push_back('+');
			Stack.push(i);
		}
		
		while(!Stack.empty() && Stack.top()==arr[idx]) {
			res.push_back('-');
			idx++;
			Stack.pop();
		}
	}
	
	if(Stack.empty())
		for(char c : res)
			cout<<c<<"\n";
		
	else cout<<"NO\n";
}
