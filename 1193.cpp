#include <iostream>
using namespace std;

void f(int n) {
	int r = 1, c = 1;
	
	while(--n) {				// �����ݺ�
	
		if((r+c)%2==0) {		// ��+���� ¦���� �� 
			
			if(r==1)
				c++;
			else {
				r--; c++;
			}
			
		} else {				// ��+���� Ȧ���� �� 
			
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
