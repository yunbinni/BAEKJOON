#include<cstdio>
#include<climits>
#include<algorithm>
int n, s, S, E, res=INT_MAX;
int arr[100004], psum[100004];

int main() {
	scanf("%d %d", &n, &s);
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
		psum[i]=psum[i-1]+arr[i];
	}
	
	S=1, E=1;
	while(S<=E) {
		if(E>n) break;
		int sum=psum[E]-psum[S-1];
		if(sum>=s) {
			res=E-S+1<res?E-S+1:res;
			S++;
		} else {
			E++;
		}
	}
	
	if(res==INT_MAX) printf("0\n");
	else printf("%d\n", res);
	
	return 0;
}
