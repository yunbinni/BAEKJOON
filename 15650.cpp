#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> IntVector;

void DFS(int L, int s)
{
	if(L > M)
	{
		for(int number : IntVector)
		{
			cout << number << " ";
		}
		
		cout << "\n";
		
		return;
	}
	
	for(int i = s; i <= N; i++)
	{
		IntVector.push_back(i);
		DFS(L + 1, i + 1);
		IntVector.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	
	DFS(1, 1);
	
	return 0;
}
