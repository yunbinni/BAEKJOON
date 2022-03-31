#include <bits/stdc++.h>
using namespace std;

const int maxN = 51;
int T, M, N, K, X, Y, ny, nx, ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[maxN][maxN];
int visited[maxN][maxN];

void dfs(int y, int x) {
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++) {
		ny = dy[i] + y;
		nx = dx[i] + x;
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		
		if(arr[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
	}
	
	return;
}

int main() {
	scanf("%d", &T);
	
	while(T--)
	{
		fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        
		ret = 0;
		
		scanf("%d %d %d", &M, &N, &K);
		
		while(K--) {
			scanf("%d %d", &X, &Y);
			arr[Y][X] = 1;
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(arr[i][j] == 1 && !visited[i][j]) {
					ret++;
					dfs(i, j);
				}
			}
		}
		
		printf("%d\n", ret);
	}
	
	return 0;
}
