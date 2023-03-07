#include <bits/stdc++.h>
using namespace std;

int N;
string input_string;
int numbers[26];

void input();
double solve(int N, string my_string, int numbers[]);

int main() {
	input();
	cout << fixed;
	cout.precision(2);
	cout << solve(N, input_string, numbers) << "\n";
	return 0;
}

void input() {
	cin >> N;
	cin >> input_string;
	for(int i = 0; i < N; i++)
		cin >> numbers[i];
}

double solve(int N, string my_string, int numbers[]) {
	double answer = 0.00;
	
	stack<double> Stack;
	
	for(char ch : my_string)
	{
		if('A' <= ch && ch <= 'Z')
			Stack.push(numbers[ch-'A']);
		
		if(ch == '+')
		{
			double b = Stack.top(); Stack.pop();
			double a = Stack.top(); Stack.pop();
			
			Stack.push(a + b);
		}
		
		if(ch == '-')
		{
			double b = Stack.top(); Stack.pop();
			double a = Stack.top(); Stack.pop();
			
			Stack.push(a - b);
		}
		
		if(ch == '*')
		{
			double b = Stack.top(); Stack.pop();
			double a = Stack.top(); Stack.pop();
			
			Stack.push(a*b);
		}
		
		if(ch == '/')
		{
			double b = Stack.top(); Stack.pop();
			double a = Stack.top(); Stack.pop();
			
			Stack.push(a/b);
		}
	}
	
	answer = Stack.top();
	
	return answer;
}
