#include<bits/stdc++.h>
using namespace std;

int main() {
	int A[6]={1, 1, 2, 2, 2, 8}, B[6];
	for(int i=0; i<6; i++) cin>>B[i];
	for(int i=0; i<6; i++) cout<<A[i]-B[i]<<" ";
	return 0;
}
