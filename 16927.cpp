#include<cstdio>
using namespace std;
typedef long long ll;

int n, m, maxL;
ll r;
int arr[304][304];

void rotate(int L) {
	if(L>maxL) return;
	int cycle=((n-2*L+2)+(m-2*L+2))*2-4;
	
	for(ll k=0; k<r%cycle; k++) {
		int lu=arr[L][L];
		int ld=arr[n-L+1][L];
		int rd=arr[n-L+1][m-L+1];
		int ru=arr[L][m-L+1];
		
		//down
		for(int i=n-L+1; i>=L+1; i--)
			arr[i][L]=arr[i-1][L];
		//right
		for(int i=m-L+1; i>=1+L; i--)
			arr[n-L+1][i]=arr[n-L+1][i-1];
		//up
		for(int i=L; i<=n-L; i++)
			arr[i][m-L+1]=arr[i+1][m-L+1];
		//left
		for(int i=L; i<=m-L; i++)
			arr[L][i]=arr[L][i+1];
			
		arr[L+1][L]=lu;
		arr[n-L+1][L+1]=ld;
		arr[n-L][m-L+1]=rd;
		arr[L][m-L]=ru;
	}
	
	rotate(L+1);
}

int main() {
	scanf("%d %d %lld", &n, &m, &r);
	maxL=n<m?n/2:m/2;
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		scanf("%d", &arr[i][j]);
	}}
	
	rotate(1);
	
	for(int i=1; i<=n; i++) {
	for(int j=1; j<=m; j++) {
		printf("%d ", arr[i][j]);
	}	printf("\n");
	}
	return 0;
}
