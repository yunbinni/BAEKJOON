#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main(void) {
	int n, data;
	stack<int> stack;
	cin >> n;
	char* order = (char*)malloc(sizeof(char)*10);
	
	while(n--) {
		// 명령 받기
		scanf("%s", order);
		
		// push
		if(order[0]=='p' && order[1]=='u' && order[2]=='s' && order[3]=='h') {
			scanf("%d", &data);
			stack.push(data);
		}
		
		// pop
		else if(order[0]=='p' && order[1]=='o' && order[2]=='p') {
			if(stack.empty())
				printf("-1\n");
			
			else {
				printf("%d\n", stack.top());
				stack.pop();
			}
		}
		
		// size
		else if(order[0]=='s' && order[1]=='i' && order[2]=='z' && order[3]=='e') {
			printf("%d\n", stack.size());
		}
		
		// empty
		else if(order[0]=='e' && order[1]=='m' && order[2]=='p' && order[3]=='t' && order[4]=='y') {
			printf("%d\n", stack.empty());
		}
		
		// top
		else if(order[0]=='t' && order[1]=='o' && order[2]=='p') {
			if(stack.empty())
				printf("-1\n");
			
			else
				printf("%d\n", stack.top());
		}
	}
	
	return 0;
}
