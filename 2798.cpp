#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int N, M, in;
vector<int> v, numV, sumV;

void combi(int s, vector<int> v) {
	
	if(v.size() == 3) {
		int sum = 0;
		for(int a : v) sum += a;
		sumV.push_back(sum);
		return;
	}
	
	for(int i = s; i < N; i++) {
		v.push_back(numV[i]);
		combi(i+1, v);
		v.pop_back();
	}
	return;
}

int main() {
	int d = INT_MAX, res;
	
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d", &in);
		numV.push_back(in);
	}
	
	combi(0, v);
	
	for(int s : sumV) {
		if(s <= M && M - s < d) {
			d = M - s;
			res = s;
		}
	}
	
	printf("%d", res);
	
	return 0;
}
