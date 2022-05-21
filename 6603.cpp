#include<bits/stdc++.h>
using namespace std;

int arr[6];
vector<int> S;

void DFS(int s, int L) {
	if(L==6) {
		for(int i=0; i<6; i++) printf("%d ", arr[i]); printf("\n");
		return;
	}
	for(int i=s; i<S.size(); i++) {
		arr[L]=S[i];
		DFS(i+1, L+1);
	}
}

int main() {
	int k;
	while(scanf("%d", &k) && k!=0) {
		int in;
		
		for(int i=0; i<k; i++) {
			scanf("%d", &in);
			S.push_back(in);
		}
		DFS(0, 0);
		printf("\n");
		S.clear();
	}
	return 0;
}
