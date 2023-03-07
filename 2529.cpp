#include <bits/stdc++.h>
using namespace std;

int k;
char arr[20];
bool visited[10];

long long maxN = 0;
long long minN = 9876543210;

string maxN_str;
string minN_str;

void input();
void DFS(int L);
bool check();
void output();

		
int main() {
	input();
	DFS(1);
	output();
	return 0;
}


void input() {
	cin >> k;
	
	for(int i = 2; i <= 2*k; i += 2)
		cin >> arr[i];
}

void DFS(int L) {
	
	if(L > 2*k + 1)
	{
		if(check())
		{
			long long res;
			string res_str;
			
			for(int i = 1; i <= 2*k + 1; i += 2)
				res_str.push_back(arr[i]);
				
			res = stoll(res_str);
			
			if(res > maxN)
				{ maxN = res; maxN_str = res_str; }
			if(res < minN) 
				{ minN = res; minN_str = res_str; }
		}
		
		return;
	}
	
	for(int i = 0; i <= 9; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			arr[L] = i + '0';
			DFS(L + 2);
			visited[i] = false;
		}
	}
}

bool check() {
	
	for(int i = 2; i <= 2*k; i += 2)
	{
		if(arr[i] == '>') {
			if(arr[i - 1] <= arr[i + 1])
				return false;
		}
		
		if(arr[i] == '<') {
			if(arr[i - 1] >= arr[i + 1])
				return false;
		}
	}
	
	return true;
}

void output() {
	cout << maxN_str << "\n";
	cout << minN_str << "\n";
}
