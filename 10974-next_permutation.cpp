#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	vector<int> in;
	for(int i=1; i<=n; i++) in.push_back(i);
	
	do {
		for(auto a : in) printf("%d ", a);
		printf("\n");
		
	} while(next_permutation(in.begin(), in.end()));
	
	return 0;
}
