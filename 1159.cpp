#include <cstdio>
#include <iostream>
using namespace std;

int N, a[26] = { 0, };
string s;

void f(int* a) {
	int i, cnt = 0;
	
	for(i = 0; i < 26; i++) {
		if(a[i] >= 5) {
			printf("%c", i+97);
			cnt++;
		}
	}
	
	if(cnt == 0) printf("PREDAJA");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> s;
		
		a[s[0] - 97]++;
	}
	
	f(a);
	
	return 0;
}
