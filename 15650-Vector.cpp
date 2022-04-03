#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void f(int in) {
	if(v.size()>=m) {
		for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
		printf("\n");
		v.pop_back();
		return;
	}
	
	for(int i=in+1; i<=n; i++) {
		v.push_back(i);
		f(i);
	}
	v.pop_back();
}

int main() {
	scanf("%d %d", &n, &m);
	f(0);
	return 0;
}
