#include <bits/stdc++.h>
using namespace std;

int w[51];
int h[51];

int main() {
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> h[i];
	
	for(int i = 1; i <= n; i++) {
		int rank = 1;
		
		for(int j = 1; j <= n; j++)
			if(w[i] < w[j] && h[i] < h[j]) rank++;
		
		cout << rank << ' ';
	}
	
	return 0;
}
