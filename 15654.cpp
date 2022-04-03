#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int out[10], visited[10];

void f(int pos, vector<int>& in) {
	int i;
	if(pos>m) {
		//Ãâ·Â
		for(i=1; i<=m; i++) printf("%d ", out[i]);
		printf("\n");
		return;
	}
	
	for(i=1; i<=n; i++) {
		if(visited[i]==1) continue;
		visited[i]=1;
		out[pos]=in[i];
		f(pos+1, in);
		visited[i]=0;
	}
}

int main() {
	int i, tmp;
	scanf("%d %d", &n, &m);
	vector<int> in; in.push_back(0);
	for(i=1; i<=n; i++) {
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	sort(in.begin(), in.end());
	
	f(1, in);
	return 0;
}
