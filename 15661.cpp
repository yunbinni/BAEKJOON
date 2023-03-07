#include <bits/stdc++.h>
using namespace std;

int N;
int S[24][24];
int check[24];
int answer = 987654321;

void input() {
	cin >> N;
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> S[i][j];
}

void DFS(int L, int s) {

	if(L > N/2 + 1)
		return;

	if(L > 1)
	{
		int start = 0;
		int link = 0;
		
		for(int i = 1; i <= N - 1; i++) {
			for(int j = i + 1; j <= N; j++)
			{
				if(check[i] && check[j])
					start += S[i][j] + S[j][i];
				
				else if(!check[i] && !check[j])
					link += S[i][j] + S[j][i];
			}
		}
		
		answer = min(answer, abs(start - link));
	}
	
	for(int i = s; i <= N; i++)
	{
		check[i] = true;
		DFS(L + 1, i + 1);
		check[i] = false;
	}
}

void output() {
	cout << answer << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	DFS(1, 1);
	output();
	
	return 0;
}
