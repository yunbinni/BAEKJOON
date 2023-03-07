#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int factorial[13];
	factorial[0] = 1;
	factorial[1] = 1;
	
	for(int i = 2; i <= N; i++)
		factorial[i] = factorial[i - 1] * i;
	
	cout << factorial[N] << "\n";
	
	return 0;
}
