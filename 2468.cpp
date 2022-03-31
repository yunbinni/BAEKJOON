#include <bits/stdc++.h>
using namespace std;

const int maxN = 101;
int N, ret = 1;
int arr[maxN][maxN];
int c[maxN][maxN];
int visited[maxN][maxN];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		
		if(c[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(int high = 1; high < 101; high++) {
		
		fill(&visited[0][0], &visited[0][0] + maxN*maxN, 0);
		
		int temp = 0;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(c[i][j] == 1) continue;
				if(arr[i][j] <= high) c[i][j] = 1;
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(c[i][j] == 0 && !visited[i][j]) {
					dfs(i, j);
					temp++;
				}
			}
		}
		
		ret = max(ret, temp);
	}
	
	printf("%d\n", ret);
	
	return 0;
}
