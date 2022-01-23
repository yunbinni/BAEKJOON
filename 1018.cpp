#include <bits/stdc++.h>
using namespace std;

char change(char c) {
	if(c == 'B')		return 'W';
	else if(c == 'W')	return 'B';
}

char cmpArr1[8][8];
char cmpArr2[8][8];

int main() {
	int N, M, cnt1 = 9999, cnt2 = 9999;
	char std = 'B', inputArr[51][51];
	
	//비교배열 초기화
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			cmpArr1[i][j] = std;
			cmpArr2[i][j] = change(std);
			std = change(std);
		}
		std = change(std);
	}
	
	//배열 입력받기
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> inputArr[i][j];
		}
	}
	
	//틀 맞추기
	for(int I = 0; I < N - 8 + 1; I++) {
		for(int J = 0; J < M - 8 + 1; J++) {
			
			int a = 0, b = 0;
			
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					
					if(inputArr[i+I][j+J] != cmpArr1[i][j]) a++;
					if(inputArr[i+I][j+J] != cmpArr2[i][j]) b++;
				}
			}
			
			if(a < cnt1) cnt1 = a;
			if(b < cnt2) cnt2 = b;
			
		}
	}
	
	//정답출력
	if(cnt1 < cnt2)	cout << cnt1;
	else			cout << cnt2;

	return 0;
}
