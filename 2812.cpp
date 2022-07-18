#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	string inp;
	vector<char> res;
	cin>>n>>k;
	cin>>inp;
	
	for(int i=0; i<inp.size(); i++) {
		while(res.size()>0 && inp[i]>res.back() && k>0) {
			k--;
			res.pop_back();
		}
		res.push_back(inp[i]);
	}
	while(k>0) {
		k--;
		res.pop_back();
	}
	
	for(int i=0; i<res.size(); i++) cout<<res[i];
	return 0;
}
