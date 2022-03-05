#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<int, string> m1;
map<string, int> m2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> s;
		m1[i+1] = s;
		m2[s] = i+1;
	}
	
	for(int j = 0; j < M; j++) {
		cin >> s;
		
		if(atoi(s.c_str()) == 0)
			cout << m2[s] << '\n';
		
		else
			cout << m1[atoi(s.c_str())] << '\n';
	}
	
	return 0;
}
