#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> S;

vector<bool> check;

int answer = 100;

void input();
void DFS(int L, int s);
void output();

int main() {
	
	input();
	DFS(1, 1);
	output();
	
	return 0;
}

void input() {
	cin >> N;
	
	S.assign(N + 1, vector<int>(N + 1, 0));
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> S[i][j];
	
	check.assign(N + 1, false);
}

void DFS(int L, int s) { // level, start
	
	if(L > N/2)
	{
		vector<int> start;
		vector<int> link;
		
		for(int i = 1; i <= N; i++)
		{
			if(check[i]) start.push_back(i);
			if(!check[i]) link.push_back(i);
		}
		
		int start_stats = 0;
		int link_stats = 0;
		
		for(int i : start) {
			for(int j : start)
			{
				if(i == j) continue;
				start_stats += S[i][j];
			}
		}
		
		for(int i : link) {
			for(int j : link)
			{
				if(i == j) continue;
				link_stats += S[i][j];
			}
		}
		
		answer = min(answer, abs(start_stats - link_stats));
		
		return;
	}
	
	for(int i = s; i <= N; i++)
	{
		if(!check[i])
		{
			check[i] = true;
			DFS(L + 1, i + 1);
			check[i] = false;
		}
	}
}

void output() {
	cout << answer << "\n";
}
