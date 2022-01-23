#include <iostream>
using namespace std;

int f1(int n) {
	if(n == 1)
		return 1;
	else
		return f1(n - 1) * 2 + 1;
}

void f2(int from, int by, int to, int n) {
	if(n == 1)
		cout << from << " " << to << "\n";
	
	else {
		f2(from, to, by, n - 1);
		cout << from << " " << to << "\n";
		f2(by, from, to, n - 1);
	}
}

int main(void) {
	int n;
	cin >> n;
	
	cout << f1(n) << "\n";
	f2(1, 2, 3, n);
	return 0;
}
