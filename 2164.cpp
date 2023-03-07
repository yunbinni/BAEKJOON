#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> dQ;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		dQ.push_back(i);
	}
	
	int count = 0;
	
	while(dQ.size() > 1)
	{
		if(count%2 == 0) dQ.pop_front();
		if(count%2 == 1)
		{
			int front = dQ.front(); dQ.pop_front();
			dQ.push_back(front);
		}
		
		count++;
	}
	
	cout << dQ[0] << "\n";
	
	return 0;
}
