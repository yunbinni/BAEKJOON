#include <iostream>
using namespace std;

int N, S;
int Array[20];

void input()
{
	cin >> N >> S;
	
	for(int i = 0; i < N; ++i)
		cin >> Array[i];
}

int solution()
{
	int result = 0;
	
	for(int subset = 1; subset < (1 << N); ++subset)
	{
		int sum = 0;
		
		for(int i = 0; i < N; ++i)
		{
			if(subset & (1 << i))
			{
				sum += Array[i];
			}
		}
		
		if(sum == S) ++result;
	}
			
	return result;
}

int main()
{
	input();
	cout << solution() << "\n";
	return 0;
}
