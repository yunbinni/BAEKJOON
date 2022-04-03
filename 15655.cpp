#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int out[10], visited[10];

void f(int pos, int s, vector<int>& in) {
	int i;
	if(pos>=m) {
		//Ãâ·Â
		for(i=0; i<m; i++) printf("%d ", out[i]);
		printf("\n");
		return;
	}
	
	for(i=s; i<n; i++) {
		out[pos]=in[i];
		f(pos+1, i+1, in);
	}
}

int main() {
	int i, tmp;
	scanf("%d %d", &n, &m);
	vector<int> in;
	for(i=0; i<n; i++) {
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	sort(in.begin(), in.end());
	
	f(0, 0, in);
	return 0;
}
