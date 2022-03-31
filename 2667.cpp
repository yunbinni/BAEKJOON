#include <bits/stdc++.h>
using namespace std;

int n, arr[26][26], cnt, area;
bool visited[26][26];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	area++;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1) continue;
		if(arr[ny][nx] == 1 && visited[ny][nx] == 0)
			dfs(ny, nx);
	}
	return;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
				v.push_back(area);
				area = 0;
			}
		}
	}
	
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for(int e : v) cout << e << "\n";
	
	return 0;
}
