#include<bits/stdc++.h>
using namespace std;

int arr[9][9];
vector<pair<int, int> > YX;
bool chkRow[9][9], chkCol[9][9], chkGrp[9][9];

int findGrp(int i, int j) {
	return (i/3)*3+(j/3);
}

void DFS(int L) {
	if(L==YX.size()) {
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) cout<<arr[i][j]<<' ';
			cout<<"\n";
		}
		exit(0);
	}
	
	int y=YX[L].first, x=YX[L].second, grp=findGrp(y, x);
	for(int i=1; i<=9; i++) {
		if(chkRow[y][i]==false && chkCol[x][i]==false && chkGrp[grp][i]==false) {
			chkRow[y][i]=chkCol[x][i]=chkGrp[grp][i]=true;
			arr[y][x]=i;
			DFS(L+1);
			arr[y][x]=0;
			chkRow[y][i]=chkCol[x][i]=chkGrp[grp][i]=false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=0; i<9; i++)
	for(int j=0; j<9; j++) {
		cin>>arr[i][j];
		if(arr[i][j]==0) YX.push_back(make_pair(i, j));
		else chkRow[i][arr[i][j]]=chkCol[j][arr[i][j]]=chkGrp[findGrp(i, j)][arr[i][j]]=true;
	}
	DFS(0);
	return 0;
}
