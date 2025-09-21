#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *head=NULL, *tail=NULL;

void append(int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		perror("Failed to dynamically allocate memory!\n");
		return;
	}
	newNode->data = data;
	newNode->next = newNode;
	if(!head) {
		head = tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->next = head;
	tail = newNode;
}

void delete_begin() {
	if(!head) return;
	if(head == tail) {
		free(head);
		head = tail = NULL;
		return;
	}
	struct Node *temp = head;
	tail->next = head->next;
	head = head->next;
	free(temp);
}

void delete_end() {
	if(!head) return;
	if(head == tail) {
		free(head);
		head = tail = NULL;
		return;
	}
	struct Node *temp = head;
	for(;temp->next!=tail;temp=temp->next);
	temp->next = head;
	free(tail);
	tail = temp;
}

void display() {
	if (!head) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = head;
	printf("List: ");
	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("(back to head)\n");
}

int main() {
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	delete_begin();
	delete_end();
	display();

	while(head) delete_end();

	return 0;
}
