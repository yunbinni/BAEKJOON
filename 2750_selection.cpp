#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, in;
vector<int> v;

void selection_sort(vector<int>& v) {
	
	//Á¤·Ä
	for(int i = v.size(); i > 0; i--) {
		
		int idx = 0;
		
		for(int j = 0; j < i; j++) if(v[j] > v[idx]) idx = j;
		
		swap(v[i - 1], v[idx]);
	}
	
	//show
	for(int a : v) cout << a << '\n';
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	
	selection_sort(v);
	
	return 0;
}
