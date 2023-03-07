#include <bits/stdc++.h>
using namespace std;

int d[6][3] = {{0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};

struct Coord {
	int y;
	int x;
	int z;
	
	Coord(int py, int px, int pz) {
		y = py;
		x = px;
		z = pz;
	}
};

int M, N, H;
int Boxes[102][102][102];
queue<Coord> Q;

void input()
{
	cin >> M >> N >> H;
	
	for(int h = 1; h <= H; ++h)
		for(int n = 1; n <= N; ++n)
			for(int m = 1; m <= M; ++m)
			{
				cin >> Boxes[n][m][h];
				
				if(Boxes[n][m][h] == 1)
					Q.push(Coord(n, m, h));
			}
}

int getNotRipen()
{
	int notRipen = 0;
	
	for(int h = 1; h <= H; ++h)
		for(int n = 1; n <= N; ++n)
			for(int m = 1; m <= M; ++m)
				if(Boxes[n][m][h] == 0)
					notRipen++;
	
	return notRipen;
}

bool isInternal(Coord c)
{
	if(c.y >= 1 && c.y <= N && c.x >= 1 && c.x <= M && c.z >= 1 && c.z <= H)
		return true;
	
	return false;
}

int solution()
{
	while(!Q.empty())
	{
		Coord current = Q.front(); Q.pop();
		
		for(int i = 0; i < 6; ++i)
		{
			Coord next = Coord(current.y + d[i][0], current.x + d[i][1], current.z + d[i][2]);
			
			if(isInternal(next))
			{
				if(Boxes[next.y][next.x][next.z] == 0)
				{
					Boxes[next.y][next.x][next.z] = Boxes[current.y][current.x][current.z] + 1;
					Q.push(next);
				}
			}
		}
	}
	
	if(getNotRipen())
		return -1;
	
	int result = 0;
	
	for(int h = 1; h <= H; ++h)
		for(int n = 1; n <= N; ++n)
			for(int m = 1; m <= M; ++m)
				if(Boxes[n][m][h] > result)
					result = max(Boxes[n][m][h], result);
	
	return result - 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	input();
	cout << solution();
	
	return 0;
}
