#include <bits/stdc++.h>
using namespace std;

int n, m;

void input();
int solve();
long long count_X(int n, int x);

int main() {
	ios_base::sync_with_stdio(0);
	input();
	cout << solve() << "\n";
	return 0;
}

void input() {
	cin >> n >> m;
}

int solve() {
	int answer = 0;
	
	long long twoes = 0;
	long long fives = 0;
	
	twoes = count_X(n, 2) - count_X(n - m, 2) - count_X(m, 2);
	fives = count_X(n, 5) - count_X(n - m, 5) - count_X(m, 5);
	
	answer = min(twoes, fives);
	
	return answer;
}

long long count_X(int n, int x) {
	long long answer = 0;
	
	for(long long i = x; i <= n; i *= x)
	{
		answer += n/i;
	}
	
	return answer;
}
