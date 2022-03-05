#include <iostream>
#include <algorithm>
using namespace std;

int N, heap[1000001];

void heap_sort(int* heap, int size) {
	//최대 힙 구성
	for(int i = 1; i < size; i++) {
		int c = i;
	
		do {
			int root = (c - 1)/2;
			
			if(heap[root] < heap[c]) swap(heap[root], heap[c]);
			
			c = root;
		} while(c != 0);
	}
	
	//정렬
	for(int i = size - 1; i >= 0; i--) {
		swap(heap[0], heap[i]);
		
		int root = 0;
		int c = 1;
		
		do {
			c = 2*root + 1;
			
			if(c < i - 1 && heap[c] < heap[c + 1]) c++;
			
			if(c < i && heap[root] < heap[c]) swap(heap[root], heap[c]);
			
			root = c;
		} while(c < i);
	}
	
	//show
	for(int i = 0; i < size; i++) cout << heap[i] << '\n';
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> heap[i];
	
	heap_sort(heap, N);
	
	return 0;
}
