#include <bits/stdc++.h>
using namespace std;

const int maxN = 104;
int M, N, K, cnt = 0, temp = 0;
int arr[maxN][maxN];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> area;

void dfs(int y, int x) {
	arr[y][x] = 1;
	
	for(int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		
		if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		
		if(arr[ny][nx] == 0) {
			arr[ny][nx] = 1;
			temp++;
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//ют╥б 
	cin >> M >> N >> K;
	
	fill(&arr[0][0], &arr[maxN - 1][maxN - 1], 0);
	
	while(K--) {
		int x1, y1, x2, y2;
		
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int i = y1; i < y2; i++) {
			for(int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(arr[i][j] == 0) {
				dfs(i, j);
				cnt++;
				area.push_back(temp + 1);
			}
			temp = 0;
		}
	}
	
	cout << cnt << "\n";
	sort(area.begin(), area.end());
	for(int a : area) cout << a << ' ';
	
	return 0;
}
