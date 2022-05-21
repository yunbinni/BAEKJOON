#include <cstdio>
using namespace std;

int a, b;
long long cnt;

void f(long long in) {
	if(in>b) return;
	else {
		if(in>=a && in<=b) cnt++;
		f(in*10+4);
		f(in*10+7);
	}
}

int main() {
	scanf("%d %d", &a, &b);
	
	f(4);
	f(7);
	
	printf("%lld\n", cnt);
	
	return 0;
}
