#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, i;
	scanf("%d", &n);
	vector<int> in(n);
	for(i=0; i<n; i++)
		scanf("%d", &in[i]);
	
	sort(in.begin(), in.end());
	
	printf("%d\n", in[0]*in[n-1]);
	
	return 0;
}
