#include <iostream>
#include <algorithm>
using namespace std;

int h[9], sum;
int sorted[7], sortedIdx = 0;

void f(int* arr) {
	
	for(int i = 0; i < 8; i++) {
		for(int j = i + 1; j < 9; j++) {
			
			if(sum - *(arr+i) - *(arr+j) == 100) {
				
				for(int k = 0; k < 9; k++) {
					if(k == i || k == j) continue;
					
					sorted[sortedIdx++] = *(arr+k);
				}
				
				sort(sorted, sorted + 7);
				
				return;
			}
		}
	}
}

int main() {
	for(int i = 0; i < 9; i++) cin >> h[i];
	
	for(int i = 0; i < 9; i++) sum += h[i];
	
	f(h);
	
	for(int i = 0; i < 7; i++) printf("%d\n", sorted[i]);
	
	return 0;
}
