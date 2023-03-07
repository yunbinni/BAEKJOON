#include <bits/stdc++.h>
using namespace std;

int N;
string order;
queue<int> Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	for(int i = 0; i <= N; i++)
	{
		getline(cin, order);
		
		if(order.substr(0, 4)  == "push")
			Q.push(stoi(order.substr(5))); // 문자열의 정수부분 시작부터
		
		if(order == "pop")
		{
				if(Q.empty())
					cout << "-1\n";
				else {
					cout << Q.front() << "\n";
					Q.pop();
				}
		}
		
		if(order == "size")
			cout << Q.size() << "\n";
		
		if(order == "empty")
		{
			if(Q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		
		if(order == "front")
		{
			if(Q.empty())
				cout << "-1\n";
			else
				cout << Q.front() << "\n";
		}
		
		if(order == "back")
		{
			if(Q.empty())
				cout << "-1\n";
			else
				cout << Q.back() << "\n";
		}
	}
	
	return 0;
}
