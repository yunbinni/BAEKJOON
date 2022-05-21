#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[52][52];
long long maxN=-1;

int getSum(int sy, int sx, int ey, int ex) {
	int i, j, sum=0;
	for(i=sy; i<=ey; i++) {
		for(j=sx; j<=ex; j++) {
			sum+=arr[i][j];
		}
	}
	return sum;
}

void sol() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	//가로줄 2개로 나누기
	for(i=1; i<=n-2; i++) {
		for(j=i+1; j<=n-1; j++) {
			long long s1 = getSum(1, 1, i, m);
			long long s2 = getSum(i+1, 1, j, m);
			long long s3 = getSum(j+1, 1, n, m);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	
	//세로줄 2개로 나누기
	for(i=1; i<=m-2; i++) {
		for(j=i+1; j<=m-1; j++) {
			long long s1 = getSum(1, 1, n, i);
			long long s2 = getSum(1, i+1, n, j);
			long long s3 = getSum(1, j+1, n, m);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	
	//'ㅓ'모양으로 나누기(세로 직사각형부터 계산) 
	for(i=2; i<=m; i++) {
		for(j=2; j<=n; j++) {
			long long s1 = getSum(1, i, n, m);
			long long s2 = getSum(1, 1, j-1, i-1);
			long long s3 = getSum(j, 1, n, i-1);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	
	//'ㅏ'모양으로 나누기(세로 직사각형부터 계산)
	for(i=1; i<=m-1; i++) {
		for(j=2; j<=n; j++) {
			long long s1 = getSum(1, 1, n, i);
			long long s2 = getSum(1, i+1, j-1, m);
			long long s3 = getSum(j, i+1, n, m);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	
	//'ㅜ'모양으로 나누기 (위사각형부터 계산)
	for(i=2; i<=n; i++) {
		for(j=2; j<=m; j++) {
			long long s1 = getSum(1, 1, i-1, m);
			long long s2 = getSum(i, 1, n, j-1);
			long long s3 = getSum(i, j, n, m);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	
	//'ㅗ'모양으로 나누기(아래사각형부터 계산)
	for(i=2; i<=n; i++) {
		for(j=2; j<=m; j++) {
			long long s1 = getSum(i, 1, n, m);
			long long s2 = getSum(1, 1, i-1, j-1);
			long long s3 = getSum(1, j, i-1, m);
			maxN = max(maxN, s1*s2*s3);
		}
	}
	printf("%lld\n", maxN);
}

int main() {
	sol();
	return 0;
}
