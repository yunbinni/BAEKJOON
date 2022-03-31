#include <iostream>
using namespace std;

int m, n, i, sum, minN, flag;

int main() {
	cin>>m>>n;
	for(i=1; i<10001; i++) {
		if(i*i>=m && i*i<=n) {
			sum+=i*i;
			if(flag==0){
				minN=i*i;
				flag=1;
			}
		}
	}
	if(sum) printf("%d\n%d", sum, minN);
	else printf("-1");
	return 0;
}
