#include <iostream>
using namespace std;

void f(int n) {
	int line = 0, sum = 0;
	
	while(n > sum) {
		line++;
		sum += line;
	}
	
	if(line%2==0)
		cout << (n - sum + line) << "/" << (sum - n + 1);
	else
		cout << (sum - n + 1) << "/" << (n - sum + line);
}

int main(void) {
	int n;
	cin >> n;
	
	f(n);
	
	return 0;
}
