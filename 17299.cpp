#include<bits/stdc++.h>
using namespace std;

const int maxN=1000001;

int N;
int A[maxN], F[maxN], NGF[maxN];

void input();
void write_F();
void solve();
void output();

int main() {
//	ios_base::sync_with_stdio(0);
	input();
	write_F();
	solve();
	output();
	return 0;
}

void input() {
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>A[i];
}

void write_F() {
	for(int i=1; i<=N; i++)
		F[A[i]]++;
}

void solve() {
	memset(NGF, -1, sizeof NGF);
	
	stack<int> Stack;
	
	for(int i=1; i<=N; i++) {
		
		while(!Stack.empty() && F[A[Stack.top()]] < F[A[i]]) {
			NGF[Stack.top()] = A[i];
			Stack.pop();
		}
		
		Stack.push(i);
	}
}

void output() {
	for(int i=1; i<=N; i++)
		cout<<NGF[i]<<" ";
}
