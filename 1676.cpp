#include <bits/stdc++.h>
using namespace std;

int N;

pair<int, int> Twoes_Fives[501];

void input();
void write_Twoes_Fives(int maxN);
pair<int, int> count_twoes_fives(int number);
void output(int N);

int main() {
	ios_base::sync_with_stdio(0);
	input();
	write_Twoes_Fives(N);
	output(N);
	return 0;
}

void input() {
	cin >> N;
}

void write_Twoes_Fives(int maxN) {
	
	Twoes_Fives[0].first = 0;
	Twoes_Fives[0].second = 0;
	
	for(int i = 1; i<=maxN; i++)
	{
		pair<int, int> now = count_twoes_fives(i);
		
		Twoes_Fives[i].first = Twoes_Fives[i - 1].first + now.first;
		Twoes_Fives[i].second = Twoes_Fives[i - 1].second + now.second;
	}
}

pair<int, int> count_twoes_fives(int number) {
	
	int twoes = 0, fives = 0;
	
	int copy_number1 = number;
	int copy_number2 = number;
	
	while(copy_number1%2 == 0)
	{
		twoes++;
		copy_number1 /= 2;
	}
	
	while(copy_number2%5 == 0)
	{
		fives++;
		copy_number2 /= 5;
	}
	
	return make_pair(twoes, fives);
}

void output(int N) {
	cout << min(Twoes_Fives[N].first, Twoes_Fives[N].second) << "\n";
}
