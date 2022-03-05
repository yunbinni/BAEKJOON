#include <iostream>
using namespace std;

int N, endNum = 0;

int isEndNum(int n) {
	int cnt = 0;
	
	while(n >= 6) {
		if(n%10 == 6)	cnt++;
		else			cnt = 0;
		
		if(cnt == 3) return 1;
		
		n /= 10;
	}
	
	return 0;
}

int main() {
	cin >> N;
	
	while(N--) {
		endNum += 1;
		
		while(!isEndNum(endNum)) endNum += 1;
	}
	
	cout << endNum;
	
	return 0;
}
