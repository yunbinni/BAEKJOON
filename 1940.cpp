#include <cstdio>
using namespace std;

int N, M;
int arr[15001];

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
	
	int cnt = 0;
	for(int i = 0; i < N - 1; i++) {
		for(int j = i + 1; j < N; j++) {
			if(arr[i] + arr[j] == M) cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
