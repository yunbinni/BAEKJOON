#include <iostream>
using namespace std;

int f(int n) {
	if(n == 1) return 1;
	
	int i = 2, j = 7, ret = 1;
	
	while(!(i <= n && n <= j)) {
		i = i + 6*ret;
		j = j + 6*(ret+1);
		ret++;
	}
	
	return ret+1;
}

int main(void) {
	int n;
	cin >> n;
	
	cout << f(n);
	
	return 0;
}
