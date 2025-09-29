#include<stdio.h>
#define SIZE 100

typedef struct {
	char st[SIZE];
	int sp;
} Stack;

typedef enum { false, true } bool;

const char opening[] = {'(', '[', '{'};
const char closing[] = {')', ']', '}'};

void init(Stack *stack) {
	stack->sp = -1;
}

bool isEmpty(Stack *stack) {
	return (stack->sp == -1);
}

bool isFull(Stack *stack) {
	return (stack->sp == SIZE-1);
}

void push(Stack *stack, char ch) {
	stack->st[++(stack->sp)] = ch;
}

char peek(Stack *stack) {
	return stack->st[stack->sp];
}

char pop(Stack *stack) {
	return stack->st[(stack->sp)--];
}

int main() {
	char str[SIZE];
	Stack stack;
	int i, j, ch;

	init(&stack);

	printf("1. Palindrome Check\n");
	printf("2. Matching parentheses check\n");
	scanf("%d", &ch);

	switch(ch) {
	case 1:
		printf("Enter a string: ");
		scanf("%s", str);

		for(i = 0; str[i]; i++) {
			push(&stack, str[i]);
		}
		for(i = 0; str[i]; i++) {
			if(str[i] != pop(&stack)) {
				printf("The string is not palindrome\n");
				return 0;
			}
		}
		printf("The string is palindrome\n");
		break;
	case 2:
		printf("Enter a string: ");
		scanf("%s", str);
		for(i = 0; str[i]; i++) {
			for(j = 0; j < sizeof(opening); j++) {
				if(str[i] == opening[j]) push(&stack, str[i]);
			}

			for(j = 0; j < sizeof(closing); j++) {
				if(str[i] != closing[j]) continue;

				if(peek(&stack) == opening[j]) pop(&stack);
				else {
					printf("Parentheses are not balanced\n");
					return 0;
				}
			}
		}
		if(isEmpty(&stack)) printf("Parentheses are balanced\n");
		else printf("Parentheses are not balanced\n");
		break;
	default:
		printf("Invalid option\n");
		main();
	}
	
	return 0;
}
