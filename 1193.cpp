#include <iostream>
using namespace std;

void f(int n) {
	int r = 1, c = 1;
	
	while(--n) {				// 전감반복
	
		if((r+c)%2==0) {		// 행+열이 짝수일 때 
			
			if(r==1)
				c++;
			else {
				r--; c++;
			}
			
		} else {				// 행+열이 홀수일 때 
			
			if(c==1)
				r++;
			else {
				r++; c--;
			}
		}
	}
	
	cout << r << "/" << c;
}

int main(void) {
	int n;
	cin >> n;
	
	f(n);
	
	return 0;
}
