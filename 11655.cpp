#include <cstdio>
using namespace std;

char s[101];

int main() {
	//입력 
	fgets(s, 101, stdin);
	
	//순회
	for(int i = 0; s[i] != '\0'; i++) {
		
		if(65 <= s[i] && s[i] <= 77 || 97 <= s[i] && s[i] <= 109)
			printf("%c", s[i] + 13);
		
		else if(78 <= s[i] && s[i] <= 90 || 110 <= s[i] && s[i] <= 122)
			printf("%c", s[i] + 13 - 26);
		
		else
			printf("%c", s[i]);
	}
	
	return 0;
}
