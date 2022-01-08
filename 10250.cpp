#include <iostream>
using namespace std;

int main(void) {
	int N, h, w, n;
	cin >> N;
	
	while(N--) {
		cin >> h >> w >> n;
		cout << (n%h ? n%h*100+n/h+1 : h*100+n/h) << endl;
	}
	
	return 0;
}
