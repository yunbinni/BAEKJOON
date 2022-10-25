#include<bits/stdc++.h>
using namespace std;

string in;

vector<int> solve(string in);
void output(vector<int> result);

int main() {
	
	while(getline(cin, in))
		output(solve(in));
	
	return 0;
}

vector<int> solve(string in) {
	
	int small=0, large=0, number=0, space=0;
	vector<int> result;
	
	for(auto it=in.begin(); it!=in.end(); it++) {
		char now=*it;
		
		if(now>='a' && now<='z')
			small++;
		
		if(now>='A' && now<='Z')
			large++;
		
		if(now>='0' && now<='9')
			number++;
		
		if(now==' ')
			space++;
	}
	
	result = {small, large, number, space};
	
	return result;
}

void output(vector<int> result) {
	for(int i : result)
		cout<<i<<" ";
	cout<<"\n";
}
