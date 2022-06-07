#include <bits/stdc++.h>
using namespace std;

int n, mx;
int inp[22][22];
int bit[5];

namespace Solve{
	int arr[22][22];

	void up(){
		queue<int> q;
		for(int j=1; j<=n; j++){
			for(int i=1; i<=n; i++){
				if(arr[i][j]) q.push(arr[i][j]), arr[i][j] = 0;
			}
			int t = 1;
			while(q.size()){
				int now = q.front(); q.pop();
				if(arr[t][j] == 0) arr[t][j] = now;
				else if(arr[t][j] == now) arr[t++][j] *= 2;
				else arr[++t][j] = now;
			}
		}
	}

	void dw(){
		queue<int> q;
		for(int j=1; j<=n; j++){
			for(int i=n; i>=1; i--){
				if(arr[i][j]) q.push(arr[i][j]), arr[i][j] = 0;
			}
			int t = n;
			while(q.size()){
				int now = q.front(); q.pop();
				if(arr[t][j] == 0) arr[t][j] = now;
				else if(arr[t][j] == now) arr[t--][j] *= 2;
				else arr[--t][j] = now;
			}
		}
	}

	void le(){
		queue<int> q;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(arr[i][j]) q.push(arr[i][j]), arr[i][j] = 0;
			}
			int t = 1;
			while(q.size()){
				int now = q.front(); q.pop();
				if(arr[i][t] == 0) arr[i][t] = now;
				else if(arr[i][t] == now) arr[i][t++] *= 2;
				else arr[i][++t] = now;
			}
		}
	}

	void ri(){
		queue<int> q;
		for(int i=1; i<=n; i++){
			for(int j=n; j>=1; j--){
				if(arr[i][j]) q.push(arr[i][j]), arr[i][j] = 0;
			}
			int t = n;
			while(q.size()){
				int now = q.front(); q.pop();
				if(arr[i][t] == 0) arr[i][t] = now;
				else if(arr[i][t] == now) arr[i][t--] *= 2;
				else arr[i][--t] = now;
			}
		}
	}
};
using namespace Solve;

void solve();

void dfs(int idx){
	if(idx == 5){
		solve(); return;
	}
	for(int i=0; i<4; i++){
		bit[idx] = i; dfs(idx+1);
	}
}

void solve(){
	memcpy(arr, inp, sizeof arr);
	for(int i=0; i<5; i++){
		if(bit[i] == 0) up();
		if(bit[i] == 1) dw();
		if(bit[i] == 2) le();
		if(bit[i] == 3) ri();
	}

	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) mx = max(mx, arr[i][j]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> inp[i][j];

	dfs(0);
	cout << mx;
}
