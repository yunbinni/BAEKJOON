#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int answer = 0;
	
	cin >> N;
	
	for(int i = 5; i <= N; i *= 5)
	{
		answer = answer + N/i;
	}
	
	cout << answer << "\n";
	
	return 0;
}
