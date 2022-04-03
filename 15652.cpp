#include <iostream>
using namespace std;

int n, m;
int arr[9];

void f(int pos) {
	int i;
	if(pos>m) {
		//รโทย
		for(i=1; i<=m; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	for(i=arr[pos-1]; i<=n; i++) {
		if(i==0) continue;
		arr[pos]=i;
		f(pos+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	f(1);
	return 0;
}
