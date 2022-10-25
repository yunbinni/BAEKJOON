#include<bits/stdc++.h>
using namespace std;

int A, B, C;

void input();
void output();

int main() {
	input();
	output();
	return 0;
}

void input() {
	cin>>A>>B>>C;
}

void output() {
	cout<<(A+B)%C<<"\n"<<((A%C) + (B%C))%C<<"\n"<<(A*B)%C<<"\n"<<((A%C)*(B%C))%C<<"\n";
}
