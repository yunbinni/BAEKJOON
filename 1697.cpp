#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[100004];
queue<int> Q;

void BFS() {
	while(!Q.empty()) {
		int x=Q.front();
		Q.pop();
		if(x==k) return;
		if(x-1>=0 && x-1<=100000 && arr[x-1]==0) {arr[x-1]=arr[x]+1; Q.push(x-1);}
		if(x+1>=0 && x+1<=100000 && arr[x+1]==0) {arr[x+1]=arr[x]+1; Q.push(x+1);}
		if(x*2>=0 && x*2<=100000 && arr[x*2]==0) {arr[x*2]=arr[x]+1; Q.push(x*2);}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	arr[n]=1;
	Q.push(n);
	BFS();
	cout<<arr[k]-1;
	return 0;
}
