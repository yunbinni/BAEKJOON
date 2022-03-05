#include <iostream>
using namespace std;

int N;
int arr[1000001], sorted[1000001];

void merge(int arr[], int m, int mid, int n) {
	int i = m;
	int j = mid+1;
	int k = m;
	
	while(i <= mid && j <= n) {
		if(arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	
	//remain
	if(i > mid)
		for(int t = j; t <= n; t++)   sorted[k++] = arr[t];
	else
		for(int t = i; t <= mid; t++) sorted[k++] = arr[t];
	
	//input
	for(int i = m; i <= n; i++) arr[i] = sorted[i];
}

void merge_sort(int arr[], int m, int n) {	
	if(m < n) {
		int mid = (m + n)/2;
		merge_sort(arr, m, mid);
		merge_sort(arr, mid+1, n);
		merge(arr, m, mid, n);
	}
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++) cin >> arr[i];
	
	//sort
	merge_sort(arr, 0, N - 1);
	
	//show
	for(int i = 0; i < N; i++) cout << arr[i] << '\n';
	
	return 0;
}
