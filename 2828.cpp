#include <bits/stdc++.h>
using namespace std;

int n, m, j, l, r, temp, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> j;
	l = 1;
	
	for(int i = 1; i <= j; i++) {
		r = l + m - 1;
		
		cin >> temp;
		
		if(l <= temp && temp <= r) continue;
		
		else {
			if(temp < l) {
				ret += (l - temp);
				l = temp;
			} else {
				l += (temp - r);
				ret += (temp - r);
			}
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
