#include <iostream>
using namespace std;

int f(int n) {
	if(n == 1) return 0;
	
	else if(n == 2) return 1;
	
	else {
		for(int i = 2; i <= n - 1; i++) {
			if(n%i==0) return 0;
		}
		return 1;
	}
}

int main(void) {
	int n, q, a = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> q;
		a += f(q);
	}
	cout << a;
	
	return 0;
}
