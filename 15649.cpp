#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visited[9];
int num[9];

void f(int pos) {
	if(pos>=m) {
		//Ãâ·Â
		for(int i=0; i<m; i++) printf("%d ", num[i]);
		printf("\n");
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(visited[i]==1) continue;
		visited[i]=1;
		num[pos]=i;
		f(pos+1);
		visited[i]=0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	f(0);
	return 0;
}
