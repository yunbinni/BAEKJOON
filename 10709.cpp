#include <iostream>
using namespace std;

int h, w, i, j, a[104][104], cnt, flag;
char ca[104][104];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> h >> w;
	
	for(i = 0; i < h; i++) {
		cin >> s;
		
		for(j = 0; j < s.size(); j++) {
			ca[i][j] = s[j];
		}
	}
	
	for(i = 0; i < h; i++) {
		cnt = 0; flag = 0;
		for(j = 0; j < w; j++) {
			if(ca[i][j] == 'c') {
				a[i][j] = cnt = 0;
				cnt++;
				flag = 1;
			} else if(flag) {
				a[i][j] = cnt++;
			} else {
				a[i][j] = -1;
			}
		}
	}
	
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
