#include <iostream>
using namespace std;

int f(int n) {
	if(n == 1) return 0;
	
	else if(n == 2) return 1;
	
	else {
		for(int i = 2; i < n; i++) {
			if(n%i==0) return 0;
		}
		return 1;
	}
}

int main(void) {
	int M, N, sum = 0, min = 0;
	cin >> M >> N;
	
	for(int i = M; i <= N; i++) {
		if(f(i) == 1) {
			sum += i;
			
			if(min == 0) min = i;
		}
	}
	
	if(min == 0)
		cout << -1;
	
	else {
		cout << sum << endl;
		cout << min;
	}
	
	return 0;
}
