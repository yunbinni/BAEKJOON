#include <bits/stdc++.h>
using namespace std;

int n;

int get_gcd(int A, int B) {
	if(B == 0) return A;
	else return get_gcd(B, A%B);
}

void input();
long long sum_of_gcd(int t, vector<int> numbers);

int main() {
	input();
	
	while(n--)
	{
		int t;
		vector<int> numbers;
		
		cin >> t;
		numbers.assign(t, 0);
		
		for(int i = 0; i < t; i++)
			cin >> numbers[i];
		
		cout << sum_of_gcd(t, numbers) << "\n";
	}
	
	return 0;
}

void input() {
	cin >> n;
}

long long sum_of_gcd(int t, vector<int> numbers) {
	long long result = 0;
	
	int len = numbers.size();
	
	for(int i = 0; i < len - 1; i++)
		for(int j = i + 1; j < len; j++)
			result += get_gcd(numbers[i], numbers[j]);
	
	return result;
}
