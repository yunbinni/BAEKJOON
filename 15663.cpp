#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int out[10], visited[10];

void f(int pos, vector<int>& in) {
	int i, bef;
	if(pos>m) {
		for(i=1; i<=m; i++) printf("%d ", out[i]);
		printf("\n");
		return;
	}
	
	bef=0;
	for(i=1; i<=n; i++) {
		if(visited[i]==1 || bef==in[i]) continue;
		visited[i]=1;
		out[pos]=in[i];
		bef=out[pos];
		f(pos+1, in);
		visited[i]=0;
	}
}

int main() {
	int i, tmp;
	vector<int> in; in.push_back(0);
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) {
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	sort(in.begin(), in.end());
	
	f(1, in);
	return 0;
}
