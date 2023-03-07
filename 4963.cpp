#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<vector<int> > graph, check;
int count;

int d[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void input();
int count_island();
void check_BFS(int i, int j);

int main() {
	while(1)
	{
		input(); // if w = 0 and h = 0, it will be closed;
		cout << count_island() << "\n";
	}
	return 0;
}

void input() {
	cin >> w >> h;
	
	if(w == 0 && h == 0)
		exit(0);
	
	graph.assign(h, vector<int>(w, 0));
	check.assign(h, vector<int>(w, 0));
	
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> graph[i][j];
}

int count_island() {
	int answer = 0;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
		{
			if(graph[i][j] == 1 && check[i][j] == 0)
			{
				check_BFS(i, j);
				answer++;
			}
		}
	}
	
	return answer;
}

void check_BFS(int i, int j) {
	queue<pair<int, int> > Q;
	
	check[i][j] = 1;
	Q.push(make_pair(i, j));
	
	while(!Q.empty())
	{
		int curRow = Q.front().first;
		int curCol = Q.front().second;
		Q.pop();
		
		for(int i = 0; i < 8; i++)
		{
			int newRow = curRow + d[i][0];
			int newCol = curCol + d[i][1];
			
			if(newRow >= 0 && newCol >= 0 && newRow < h && newCol < w) {
				if(graph[newRow][newCol] == 1 && check[newRow][newCol] == 0)
				{
					check[newRow][newCol] = 1;
					Q.push(make_pair(newRow, newCol));
				}
			}
		}
	}
}
