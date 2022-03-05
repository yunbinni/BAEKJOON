#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, i, j, in;
vector<int> v;

void insertion_sort(vector<int>& v) {
	
	//Á¤·Ä 
	for(i = 1; i < v.size(); i++) {
		int key = v[i];
		for(j = i - 1; j >= 0 && key < v[j]; j--) {
			v[j+1] = v[j];
		}
		v[j+1] = key;
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
	
	insertion_sort(v);
	
	return 0;
}
