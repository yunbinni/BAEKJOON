#include <bits/stdc++.h>
using namespace std;

int N;
deque<pair<int, int>> Balloons;

void input() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		int val;
		cin >> val;
		Balloons.push_back({i, val});
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	input();
	
	while(!Balloons.empty())
	{
		int num = Balloons.front().first;
		int val = Balloons.front().second;
		
		cout << num << " ";
		
		Balloons.pop_front();
		
		if(val > 0)
		{
			val--;
			while(val != 0)
			{
				Balloons.push_back(Balloons.front());
				Balloons.pop_front();
				val--;
			}
		}
		if(val < 0)
		{
			while(val != 0)
			{
				Balloons.push_front(Balloons.back());
				Balloons.pop_back();
				val++;
			}
		}
	}
	
	return 0;
}
