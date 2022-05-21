#include <cstdio>
#include <string>
using namespace std;

int n, in, s1, s2, b1, b2, i, j, in1, in2, in3, j1, j2, j3, cnt;
int chk[1001];

int main() {
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%d %d %d", &in, &s1, &b1);
		
		in1=(in/100)%10;
		in2=(in/10)%10;
		in3=in%10;
		
		for(j=123; j<=987; j++) {
			s2=b2=0;
			
			j1=(j/100)%10;
			j2=(j/10)%10;
			j3=j%10;
			
			if(j1*j2*j3==0 || j1==j2 || j2==j3 || j3==j1) {
				chk[j]=1;
				continue;
			}
			
			if(j1==in1) s2++;
			else if(j1==in2 || j1==in3) b2++;
			
			if(j2==in2) s2++;
			else if(j2==in3 || j2==in1) b2++;
			
			if(j3==in3) s2++;
			else if(j3==in1 || j3==in2) b2++;
			
			if(!(s1==s2 && b1==b2)) chk[j]=1;
		}
	}
	
	for(i=123; i<=987; i++)
		if(chk[i]==0) cnt++;
	
	printf("%d\n", cnt);
	
	return 0;
}
