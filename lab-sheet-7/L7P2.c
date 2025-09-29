#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 100

struct Node {
	char data;
	struct Node *prev;
};

typedef enum { false, true } bool;

void init(struct Node **stack) {
	*stack = NULL;
}

bool isEmpty(struct Node **stack) {
	return (*stack == NULL);
}

void push(struct Node **stack, char ch) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		perror("Failed to dynamically allocate memory!\n");
		return;
	}
	newNode->data = ch;
	newNode->prev = *stack;
	*stack = newNode;
}

char peek(struct Node **stack) {
	return (*stack)->data;
}

char pop(struct Node **stack) {
	char data = peek(stack);
	struct Node *temp = *stack;
	*stack = (*stack)->prev;
	free(temp);
	return data;
}

bool isOperand(char ch) {
	return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
	if(ch == '^') return 3;
	else if(ch == '*' || ch == '/') return 2;
	else if(ch == '+' || ch == '-') return 1;
	else if(ch == '(') return 0;
	return -1;
}

char infix_to_postfix(char *infix, char *postfix) {
	struct Node *stack;
	int i, p=0, n=strlen(infix);
	char ch;

	init(&stack);

	push(&stack, '(');
	infix[n] = ')';
	infix[n+1] = '\0';

	for(i = 0; infix[i]; i++) {
		if(infix[i] == '(') push(&stack, '(');
		else if(infix[i] == ')') {
			while((ch=pop(&stack)) != '(') postfix[p++] = ch;
		}
		else if(isOperand(infix[i])) postfix[p++] = infix[i];
		else if(precedence(infix[i]) >= precedence(peek(&stack))) {
			push(&stack, infix[i]);
		}
		else {
			while(peek(&stack) != '(') postfix[p++] = pop(&stack);
		}
	}
	postfix[p] = '\0';
}

int eval_postfix(char *postfix) {
	int i, n = strlen(postfix);
	struct Node *stack;

	init(&stack);

	for(i = 0; postfix[i]; i++) push(&stack, postfix[n-i-1]);
	while(stack->prev) {
		int a = pop(&stack)-'0';
		int b = pop(&stack)-'0';
		char op = pop(&stack);
		int c = 0;
		switch(op) {
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		case '*':
			c = a * b;
			break;
		case '/':
			c = a / b;
			break;
		case '^':
			c = pow(a, b);
			break;
		}
		push(&stack, (char)(c+'0'));
	}
	return pop(&stack)-'0';
}

int main() {
	char str[SIZE], postfix[SIZE]="";
	printf("Enter a string: ");
	scanf("%s", str);

	infix_to_postfix(str, postfix);
	printf("Equivalent postfix: %s\n", postfix);

	printf("Evaluated postfix: %d\n", eval_postfix(postfix));

	return 0;
}
