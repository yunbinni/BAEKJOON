#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string in;
	
	cin >> in;
	
	while(in.length()%3 != 0)
		in = '0' + in;
	
	for(int i = 0; i < in.length(); i += 3)
	{
		cout << (in[i] - '0')*4 + (in[i + 1] - '0')*2 + (in[i + 2] - '0')*1;
	}
	
	return 0;
}
