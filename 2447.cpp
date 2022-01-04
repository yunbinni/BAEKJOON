#include <iostream>

using namespace std;

void f(int r, int c, int n) {
	if ( (r/n) % 3 == 1 && (c/n) % 3 == 1)
		cout << " ";
	else if(n < 3)
		cout << "*";
	else
		f(r, c, n/3);
}

int main(void) {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			f(i, j, n);
		cout << "\n";
	}
	
	return 0;
}
