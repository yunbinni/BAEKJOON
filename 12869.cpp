#include<bits/stdc++.h>
using namespace std;

int N;
int inp[3], dp[61][61][61];

void input() {
	cin>>N;
	for(int i=0; i<N; i++) cin>>inp[i];
}

int solve(int x, int y, int z) {
	if(x==0 && y==0 && z==0) return 0;
	
	if(x<0) return solve(0, y, z);
	if(y<0) return solve(x, 0, z);
	if(z<0) return solve(x, y, 0);
	
	if(dp[x][y][z]!=-1) return dp[x][y][z];
	
	dp[x][y][z]=61;
	dp[x][y][z]=min(dp[x][y][z], solve(x-9, y-3, z-1)+1);
	dp[x][y][z]=min(dp[x][y][z], solve(x-9, y-1, z-3)+1);
	dp[x][y][z]=min(dp[x][y][z], solve(x-3, y-9, z-1)+1);
	dp[x][y][z]=min(dp[x][y][z], solve(x-3, y-1, z-9)+1);
	dp[x][y][z]=min(dp[x][y][z], solve(x-1, y-9, z-3)+1);
	dp[x][y][z]=min(dp[x][y][z], solve(x-1, y-3, z-9)+1);
	
	return dp[x][y][z];
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	memset(dp, -1, sizeof dp);
	cout<<solve(inp[0], inp[1], inp[2])<<"\n";
	return 0;
}
