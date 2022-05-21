#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int arr[MAX+1];

int main() {
	int n, k;
	queue<int> Q;
	scanf("%d %d", &n, &k);
	Q.push(n);
	arr[n]=0;
	while(!Q.empty()) {
		int loc=Q.front();
		Q.pop();
		if(loc==k) break;
		if(loc-1>=0 && arr[loc-1]==0) {
			Q.push(loc-1);
			arr[loc-1]=arr[loc]+1;
		}
		if(loc+1<=MAX && arr[loc+1]==0) {
			Q.push(loc+1);
			arr[loc+1]=arr[loc]+1;
		}
		if(loc*2<=MAX && arr[loc*2]==0) {
			Q.push(loc*2);
			arr[loc*2]=arr[loc]+1;
		}
	}
	printf("%d\n", arr[k]);
	return 0;
}
