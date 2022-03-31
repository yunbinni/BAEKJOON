#include <cstdio>
using namespace std;
typedef long long ll;
ll A, B, C;

ll go(ll a, ll b) {
	if(b == 1) return a % C;
	
	ll c = go(a, b/2);
	c = (c * c) % C;
	
	if(b%2) c = (c*a) % C;
	
	return c;
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	
	printf("%d", go(A, B));
	
	return 0;
}
