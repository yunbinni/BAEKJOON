#include <iostream>
using namespace std;

int main(void) {
	int n, T, arr[10001] = {0,};
	arr[1] = 1;
	
	for(int i = 2; i < 10001; i++) {
		for(int j = 2; i*j < 10001; j++)
			arr[i*j] = 1;
	}
	
	cin >> T;
	
	while(T--) {
		cin >> n;
		
		for(int i = n/2; i >= 2; i--) {
			if(arr[i] == 0 && arr[n - i] == 0) {
				cout << i << ' ' << n - i << endl;
				break;
			}
		}
	}
	
	return 0;
}
