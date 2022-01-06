#include <iostream>
#include <cmath>
using namespace std;

int f(double A, double B, double V) {
	return ceil((V - B) / (A - B));
}

int main(void) {
	int A, B, V;
	cin >> A >> B >> V;
	
	cout << f(A, B, V);
	
	return 0;
}
