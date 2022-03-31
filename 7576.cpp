#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pi;

int n, m, ret;
int arr[1004][1004];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pi> q;

void bfs() {
	int cnt = q.size(), cnt2 = 0; 
	while(q.size()) {
		auto e = q.front(); q.pop(); cnt2++;
		
		for(int i = 0; i < 4; i++) {
			int ny = e.first + dy[i];
			int nx = e.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] != 0) continue;
			if(arr[ny][nx] == 0) {
				arr[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
		if(cnt == cnt2 && q.size()) {
			cnt = q.size();
			cnt2 = 0;
			ret++;
		}
	}
}

int main() {
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 1) q.push({i, j});
		}
	}
	
	bfs();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}
