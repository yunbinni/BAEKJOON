#include<bits/stdc++.h>
using namespace std;

string in;

int firstPosition[26];

void init();
void input();
void solve();
void output();

int main() {
	init();
	input();
	solve();
	output();
	return 0;
}

void init() {
	memset(firstPosition, -1, sizeof firstPosition);
}

void input() {
	getline(cin, in);
}

void solve() {
	int size=in.size();
	
	for(int i=0; i<size; i++) {
		char now=in[i]-97;
		
		if(firstPosition[now]==-1)
			firstPosition[now]=i;
	}
}

void output() {
	for(int i=0; i<26; i++)
		cout<<firstPosition[i]<<" ";
}
