#include <iostream>
using namespace std;

void f(int h, int w, int n) {
	cout << (n%h ? n%h : h);
	printf("%02d\n", (n%h ? n/h+1 : n/h));
}

int main(void) {
	int N, h, w, n;
	cin >> N;
	
	while(N--) {
		cin >> h >> w >> n;
		f(h, w, n);
	}
	
	return 0;
}
