#include<stdio.h>
#define STACK_SIZE 50
#define INFIX_SIZE 50

typedef struct {
	char items[STACK_SIZE];
	int sp;
} Stack;

typedef enum {
	FALSE, TRUE
} boolean;

void init(Stack *stack) {
	stack->sp = -1;
}

boolean isEmpty(Stack *stack) {
	return (stack->sp == -1);
}

boolean isFull(Stack *stack) {
	return (stack->sp == STACK_SIZE-1);
}

void push(Stack *stack, char item) {
	if(isFull(stack)) {
		printf("Overflow\n");
		return;
	}

	stack->items[++(stack->sp)] = item;
}

char pop(Stack *stack) {
	if(isEmpty(stack)) {
		printf("Underflow\n");
		return '\0';
	}

	return stack->items[(stack->sp)--];
}

char peek(Stack *stack) {
	if(isEmpty) {
		printf("Stack is empty\n");
		return '\0';
	}

	return stack->items[stack->sp];
}

void display(Stack *stack) {
	int i;
	for(i = 0; i <= stack->sp; i++) printf("%c ", stack->items[i]);
}

boolean isOperand(char op) {
	return (op != '+' && op != '-' && op != '*' && op != '/' && op != '^' && op != '(' && op != ')');
}

int precedence(char ch) {
	if(ch == '^') return 3;
	if(ch == '*' || ch == '/') return 2;
	if(ch == '+' || ch == '-') return 1;
	if(ch == '(' || ch == ')') return 0;
}

int len(char *str) {
	int i;
	for(i = 0; str[i]; i++);
	return i;
}

int main() {
	char infix[INFIX_SIZE];
	char ch;
	int n, i;

	Stack stack, postfix;
	init(&stack);
	init(&postfix);

	printf("Enter infix expression: ");
	scanf("%s", infix);

	n = len(infix);
	if(infix[n-1] != ')') {
		infix[n] = ')';
		infix[n+1] = '\0';
	}

	push(&stack, '(');

	for(i = 0; infix[i]; i++) {
		if(isOperand(infix[i])) {
			push(&postfix, infix[i]);
		} else if(infix[i] == '(') {
			push(&stack, infix[i]);
		} else if(infix[i] == ')') {
			while((ch = pop(&stack)) != '(') push(&postfix, ch);
		} else if(precedence(infix[i]) > precedence(stack.items[stack.sp])) {
			push(&stack, infix[i]);
		} else {
			while(precedence(infix[i]) <= precedence(stack.items[stack.sp])) push(&postfix, pop(&stack));
			push(&stack, infix[i]);
		}
	}

	while((ch = pop(&stack)) != '\0') if(ch != '(') push(&postfix, ch);

	printf("Final postfix expression: \n");
	display(&postfix);

	return 0;
}
