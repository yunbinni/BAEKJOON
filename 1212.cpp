#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string in;
	string out;
	
	cin >> in;
	
	for(int i = 0; i < in.length(); i++)
	{
		out.push_back((in[i] - '0')/4 + '0');
		out.push_back((in[i] - '0')%4/2 + '0');
		out.push_back((in[i] - '0')%4%2/1 + '0');
	}
	
	while(out.front() == '0' && out.length() > 1) // for in: 0
		out = out.substr(1, string::npos);
	
	cout << out << "\n";
	
	return 0;
}
