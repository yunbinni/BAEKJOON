#include<bits/stdc++.h>
using namespace std;

const int maxN=1000001;

int M, N;
bool prime[maxN];

void input();
void checkPrime();
void output();

int main() {
	input();
	checkPrime();
	output();
	return 0;
}

void input() {
	cin>>M>>N;
}

void checkPrime() {
	memset(prime, true, sizeof prime);
	
	prime[1]=false;
	
	for(int i=2; i<=N; i++)
		for(int j=2; i*j<=N; j++)
			prime[i*j]=false;
}

void output() {
	for(int i=M; i<=N; i++)
		if(prime[i])
			cout<<i<<"\n";
}
