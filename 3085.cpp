#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
char arr[51][51];

void exchange(int oy, int ox, int cy, int cx) { //original, comparison
	char tmp=arr[oy][ox];
	arr[oy][ox]=arr[cy][cx];
	arr[cy][cx]=tmp;
}

int maxLen() {
	int ret=0, cnt=0;
	char now='_';
	
	//horizontal search
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(arr[i][j]!=now) {
				ret=max(ret, cnt);
				now=arr[i][j];
				cnt=0;
			}
			cnt++;
		}
		ret=max(ret, cnt);
		cnt=0;
	}
	
	//vertical search
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(arr[j][i]!=now) {
				ret=max(ret, cnt);
				now=arr[j][i];
				cnt=0;
			}
			cnt++;
		}
		ret=max(ret, cnt);
		cnt=0;
	}
	
	return ret;
}

void sol() {
	//horizontal exchange
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-1; j++) {
			if(arr[i][j]!=arr[i][j+1]) {
				exchange(i, j, i, j+1);
				ans=max(ans, maxLen());
				exchange(i, j, i, j+1);
			}
		}
	}
	
	//vertical exchange
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-1; j++) {
			if(arr[j][i]!=arr[j+1][i]) {
				exchange(j, i, j+1, i);
				ans=max(ans, maxLen());
				exchange(j, i, j+1, i);
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> arr[i][j];
	
	sol();

	return 0;
}
