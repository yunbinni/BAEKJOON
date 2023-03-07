#include <bits/stdc++.h>
using namespace std;

string input_string;

void input();
string solve(string my_string);

int main() {
	input();
	cout << solve(input_string) << "\n";
	return 0;
}

void input() {
	cin >> input_string;
}

string solve(string my_string) {
	
	string answer;
	
	stack<char> Stack;
	
	for(char ch : my_string)
	{
		if('A' <= ch && ch <= 'Z')
			answer.push_back(ch);
		
		if(ch == '+' || ch == '-')
		{
			while(!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/'))
			{
				answer.push_back(Stack.top());
				Stack.pop();
			}
			
			if(!Stack.empty() && (Stack.top() == '+' || Stack.top() == '-'))
			{
				answer.push_back(Stack.top());
				Stack.pop();
			}
			
			Stack.push(ch);
		}
		
		if(ch == '*' || ch == '/')
		{
			if(!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/'))
			{
				answer.push_back(Stack.top());
				Stack.pop();
			}
			
			Stack.push(ch);
		}
		
		if(ch == '(')
			Stack.push(ch);
		
		if(ch == ')')
		{
			while(Stack.top() != '(')
			{
				answer.push_back(Stack.top());
				Stack.pop();
			}
			
			// pop '('
			Stack.pop();
		}
	}
	
	while(!Stack.empty())
	{
		answer.push_back(Stack.top());
		Stack.pop();
	}
	
	return answer;
}
