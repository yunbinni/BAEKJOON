#include <iostream>
using namespace std;

int main(void) {
	int arr[15][15];		// [k][n]
	int sum = 0;
	
	// init 0 floor;
	for(int i = 1; i <= 14; i++)
		arr[0][i] = i;
	
	// init other floor;
	for(int i = 1; i <= 14; i++, sum = 0) {
		for(int j = 1; j <= 14; j++) {
			sum += arr[i - 1][j];
			arr[i][j] = sum;
		}
	}
	
	int T, k, n;
	cin >> T;
	
	for(int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
	
	return 0;
}
