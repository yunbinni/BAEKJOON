#include <iostream>
using namespace std;

int A, B, C, in, out, fare = 0;
int a[101] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B >> C;
	
	for(int i = 0; i < 3; i++) {
		cin >> in >> out;
		
		for(int j = in; j < out; j++) a[j] += 1;
	}
	
	for(int i = 1; i <= 100; i++) {
		if(a[i] == 1) fare += A;
		
		else if(a[i] == 2) fare += 2*B;
		
		else if(a[i] == 3) fare += 3*C;
	}
	
	cout << fare;
	
	return 0;
}
