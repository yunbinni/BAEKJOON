#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	// 입력 및 초기화 
	string a;
	string b;
	int i;
	int oneNum, tenNum = 0, sum = 0;
	
	stack<int> stack;
	
	cin >> a;
	cin >> b;
	
	// 계산부
	reverse(a.begin(), a.end());	a = a + "0";
	reverse(b.begin(), b.end());	b = b + "0";
	
	if( a.length() >= b.length() )
		for(i = 0; i < b.length() - a.length(); i++)
			b += "0";
	else
		for(i = 0; i < a.length() - b.length(); i++)
			a += "0";
	
	int loop = a.length() > b.length() ? a.length() : b.length();
	
	for(i = 0; i < loop; i++)
	{
		sum = (a.at(i)) - 48 + (b.at(i)) - 48 + tenNum;		// ASCII CODE
		oneNum = sum % 10;
		tenNum = sum / 10;
		
		stack.push(oneNum);
	}
	
	// 출력부
	i = 0;
	while(!stack.empty())
	{
		if(i == 0 && stack.top() == 0)
			stack.pop();
		cout << stack.top();
		stack.pop();
		i++;
	}
}

