#include <iostream>
using namespace std;

int main(void) {
	int arr[123456*2] = {0,};
	
	for(int i = 2; i <= 123456*2; i++) {
		for(int j = 2; i*j <= 123456*2; j++) {
			arr[i*j] = 1;
		}
	}
	
	int n, cnt;
	
	while(1) {
		cin >> n;
		cnt = 0;
		
		if(n == 0) break;
		
		for(int i = n + 1; i <= 2*n; i++)
			if(arr[i] == 0) cnt++;
		
		cout << cnt << endl;
	}
	
	return 0;
}
