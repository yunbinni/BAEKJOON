#include <bits/stdc++.h>
using namespace std;

string S;

void input();
vector<string> solve(string S);
void output(vector<string> Suffixes);

int main() {
	ios_base::sync_with_stdio(0);
	
	input();
	vector<string> Suffixes = solve(S);
	output(Suffixes);
	
	return 0;
}

void input() {
	cin >> S;
}

vector<string> solve(string S) {
	int Ssize = S.size();
	vector<string> answer;
	
	for(int i = 0; i < Ssize; i++)
		answer.push_back(S.substr(i));
	
	sort(answer.begin(), answer.end());
	
	return answer;
}

void output(vector<string> Suffixes) {
	for(string suffix : Suffixes)
		cout << suffix << "\n";
}
