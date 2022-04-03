#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[9];

void f(int in, int s) {
	int i;
	if(in>=m) {
		for(i=0; i<m; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	for(i=s; i<=n; i++) {
		arr[in]=i;
		f(in+1, i+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	f(0, 1);
	return 0;
}
