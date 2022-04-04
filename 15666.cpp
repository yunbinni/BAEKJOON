#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int out[10];

void f(int pos, int s, vector<int>& in) {
	int i, bef;
	if(pos>m) {
		for(i=1; i<=m; i++) printf("%d ", out[i]);
		printf("\n");
		return;
	}
	
	bef=0;
	for(i=s; i<=n; i++) {
		if(bef==in[i]) continue;
		out[pos]=in[i];
		bef=out[pos];
		f(pos+1, i, in);
	}
}

int main() {
	int i, tmp;
	vector<int> in; in.push_back(0);
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) {
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	sort(in.begin(), in.end());
	
	f(1, 1, in);
	return 0;
}
