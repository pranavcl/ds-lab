#include<stdio.h>
#include<stdlib.h>

struct Node {
	float coeff;
	float expo;
	struct Node *next, *prev;
};

void sort(struct Node *head) {
	int swapped;
	struct Node *temp;
	float swap_expo, swap_coeff;
	do {
		swapped = 0;
		for(temp = head; temp->next; temp=temp->next) {
			if(temp->expo < temp->next->expo) {
				swap_expo = temp->expo;
				temp->expo = temp->next->expo;
				temp->next->expo = swap_expo;

				swap_coeff = temp->coeff;
				temp->coeff = temp->next->coeff;
				temp->next->coeff = swap_coeff;
				swapped = 1;
			}
		}
	} while(swapped);
}

void append(float coeff, float expo, struct Node **head, struct Node **tail) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		perror("Failed to dynamically allocate memory!\n");
		return;
	}
	newNode->coeff = coeff;
	newNode->expo = expo;
	newNode->next = newNode->prev = NULL;
	if(!(*head)) {
		*head = *tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	newNode->prev = *tail;
	*tail = newNode;
}

void take_input(struct Node **head, struct Node **tail, char c) {
	int i, n;
	float coeff, expo;
	printf("Enter the number of terms in the polynomial %c: ", c);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter the coeffecient of term %d: ", i+1);
		scanf("%f", &coeff);
		printf("Enter the exponent of term %d: ", i+1);
		scanf("%f", &expo);
		append(coeff, expo, head, tail);
	}
	sort(*head);
}

void add(struct Node **head3, struct Node **tail3, struct Node *head1, struct Node* head2) {
	while(head1 && head2) {
		if(head1->expo == head2->expo) {
			append(head1->coeff+head2->coeff, head1->expo, head3, tail3);
			head1 = head1->next;
			head2 = head2->next;
		} else if(head1->expo > head2->expo) {
			append(head1->coeff, head1->expo, head3, tail3);
			head1 = head1->next;
		} else if(head2->expo > head1->expo) {
			append(head2->coeff, head2->expo, head3, tail3);
			head2 = head2->next;
		}
	}
	if(!head1) head1 = head2;
	for(;head1;head1=head1->next) append(head1->coeff, head1->expo, head3, tail3);
}

void empty(struct Node *head) {
	struct Node *temp;
	while(head) {
		temp = head;
		head=head->next;
		free(temp);
	}
}

void display(struct Node *head) {
	struct Node *temp = head;
	for(;temp->next;temp=temp->next) {
		printf("%.2fx^%.2f + ", temp->coeff, temp->expo);
	}
	printf(" %.2fx^%.2f\n", temp->coeff, temp->expo);
}

int main() {
	struct Node *head1, *tail1, *head2, *tail2, *head3, *tail3;
	head1 = tail1 = head2 = tail2 = head3 = tail3 = NULL;
	take_input(&head1, &tail1, 'A');
	take_input(&head2, &tail2, 'B');
	display(head1);
	printf("+\n");
	display(head2);
	printf("=\n");
	add(&head3, &tail3, head1, head2);
	display(head3);
	empty(head1);
	empty(head2);
	empty(head3);
	return 0;
}
