#include <bits/stdc++.h>
using namespace std;

int main() {
	string A, B, C, D;
	
	cin >> A >> B >> C >> D;
	
	string AB = A + B;
	string CD = C + D;
	
	long long AB_llong = stol(AB);
	long long CD_llong = stol(CD);
	
	cout << AB_llong + CD_llong << "\n";
	
	return 0;
}
