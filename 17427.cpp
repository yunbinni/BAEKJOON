#include<cstdio>

int main(){
	int n,i;
	long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) sum+=(n/i)*i;
	printf("%ld",sum);
	return 0;
}
