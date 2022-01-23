#include <stdio.h>

// 노드 
typedef struct _node {
	int data;
	struct _node* below;
} Node;

// 스택
typedef struct _stack {
	Node* head;
	int numOfData;
} Stack;

void init(Stack* pstack) {
	pstack->head = NULL;
	pstack->numOfData = 0;
}

void push(Stack* pstack, int data) {
	pstack->numOfData += 1;
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->below = pstack->head;
	
	pstack->head = newNode;
}

int pop(Stack* pstack) {
	if(empty(pstack)) return -1;
	
	pstack->numOfData -= 1;
	
	Node* rNode = pstack->head;
	int retData = pstack->head->data;
	
	pstack->head = pstack->head->below;
	
	free(rNode);
	
	return retData;
}

int size(Stack* pstack) {
	return pstack->numOfData;
}

int empty(Stack* pstack) {
	if(pstack->numOfData)	return 0;	// 채워져있으면 0
	else					return 1;	// 비어있으면 1 
}

int top(Stack* pstack) {
	if(empty(pstack)) return -1;
	
	return pstack->head->data;
}

int main(void) {
	int n, data;
	scanf("%d", &n);
	char* order = (char*)malloc(sizeof(char)*10);
	
	Stack stack;
	init(&stack);
	
	while(n--) {
		// 명령 받기
		scanf("%s", order);
		
		// push
		if(order[0]=='p' && order[1]=='u' && order[2]=='s' && order[3]=='h') {
			scanf("%d", &data);
			push(&stack, data);
		}
		
		// pop
		else if(order[0]=='p' && order[1]=='o' && order[2]=='p') {
			printf("%d\n", pop(&stack));
		}
		
		// size
		else if(order[0]=='s' && order[1]=='i' && order[2]=='z' && order[3]=='e') {
			printf("%d\n", size(&stack));
		}
		
		// empty
		else if(order[0]=='e' && order[1]=='m' && order[2]=='p' && order[3]=='t' && order[4]=='y') {
			printf("%d\n", empty(&stack));
		}
		
		// top
		else if(order[0]=='t' && order[1]=='o' && order[2]=='p') {
			printf("%d\n", top(&stack));
		}
	}
	
	return 0;
}
