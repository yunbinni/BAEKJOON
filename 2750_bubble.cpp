#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, in;
vector<int> v;

void bubble_sort(vector<int>& v) {
	
	//Á¤·Ä 
	for(int i = v.size()-1; i >= 0; i--) {
		for(int j = 0; j < i; j++) {
			if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
		}
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
	
	bubble_sort(v);
	
	return 0;
}
