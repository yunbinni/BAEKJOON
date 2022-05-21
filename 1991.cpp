#include<iostream>
using namespace std;

pair<char, char> Tree[26];

void PreOrder(char cur) {
	if(cur=='.') return;
	cout<<cur;
	PreOrder(Tree[cur-'A'].first);
	PreOrder(Tree[cur-'A'].second);
}

void InOrder(char cur) {
	if(cur=='.') return;
	InOrder(Tree[cur-'A'].first);
	cout<<cur;
	InOrder(Tree[cur-'A'].second);
}

void PostOrder(char cur) {
	if(cur=='.') return;
	PostOrder(Tree[cur-'A'].first);
	PostOrder(Tree[cur-'A'].second);
	cout<<cur;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	char p, l, r;
	cin>>n;
	while(n--) {
		cin>>p>>l>>r;
		Tree[p-'A']=make_pair(l, r);
	}
	
	PreOrder('A'); cout<<"\n";
	InOrder('A'); cout<<"\n";
	PostOrder('A'); cout<<"\n";
	
	return 0;
}
