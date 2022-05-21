#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, c;
vector<char> in, pw;

bool chk() {
	int std1=0;
	for(int i=0; i<l; i++) {
		if(pw[i]=='a' || pw[i]=='e' || pw[i]=='i' || pw[i]=='o' || pw[i]=='u')
			std1++;
	}
	if(std1>=1 && l-std1>=2) return true;
	return false;
}

void DFS(int L) {
	if((int)pw.size()==l) {
		if(chk()) {
			for(int i=0; i<l; i++) cout<<pw[i];
			cout<<"\n";
		}
		return;
	}
	for(int i=L; i<c; i++) {
		pw.push_back(in[i]);
		DFS(i+1);
		pw.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>l>>c;
	for(int i=0; i<c; i++) {
		char tmp;
		cin>>tmp;
		in.push_back(tmp);
	}
	sort(in.begin(), in.end());
	DFS(0);
	return 0;
}
