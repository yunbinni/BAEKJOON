#include <iostream>
using namespace std;

long long int f(int s, int e) {
	long long int d = e - s;		// distance
	long int n = 1;
	
	while(n*n < d)
		n++;
	
	return n*n - d < d - (n-1)*(n-1) ? 2*n - 1 : 2*n - 2;
}

int main(void) {
	long long int n, s, e;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> s >> e;
		cout << f(s, e) << endl;
	}
	
	return 0;
}
