#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000001], tmp[1000001];

void merge(int arr[], int s, int mid, int e) {
	int a=s;
	int b=mid+1;
	int idx=s;
	
	while(a<=mid && b<=e) {
		if(arr[a]<arr[b])
			tmp[idx++]=arr[a++];
		else
			tmp[idx++]=arr[b++];
	}
	
	//remain
	if(a>mid)
		for(int t=b; t<=e; t++)
			tmp[idx++]=arr[t];
	else
		for(int t=a; t<=mid; t++)
			tmp[idx++]=arr[t];
	
	for(int i=s; i<=e; i++) arr[i]=tmp[i];
}

void merge_sort(int arr[], int s, int e) {	
	if(s<e) {
		int mid=(s+e)/2;
		merge_sort(arr, s, mid);
		merge_sort(arr, mid+1, e);
		merge(arr, s, mid, e);
	}
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>arr[i];
	merge_sort(arr, 0, n-1);
	for(int i=0; i<n; i++) cout<<arr[i]<<"\n";
	return 0;
}
