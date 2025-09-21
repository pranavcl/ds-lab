#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *prev, *next;
} *head=NULL, *tail=NULL;

const char *memfail = "Failed to dynamically allocate memory!\n";
const char *notfound = "Element not found!\n";
const char *bar = "========================================\n";

void lastsert(int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		perror(memfail);
		return;
	}
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	if(!head) {
		head = tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

void last_delete() {
	if(!head) return;
	if(head == tail) {
		free(head);
		head = tail = NULL;
		return;
	}
	tail->prev->next = NULL;
	struct Node *temp = tail;
	tail = tail->prev;
	free(temp);
}

void insert(int n, int data) {
	int i;
	if(n<1) return;
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)), *temp;
	if(!newNode) {
		perror(memfail);
		return;
	}
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	if(n == 1) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
	for(i = 1, temp=head; i < n; i++, temp=temp->next);
	if(!temp) {
		perror("Invalid position for insertion\n");
		free(newNode);
		return;
	}
	temp->prev->next = newNode;
	newNode->prev = temp->prev;
	newNode->next = temp;
	temp->prev = newNode;
}

void delete(int n) {
	if(n<1 || !head) return;
	int i;
	struct Node *temp = head;
	if(n == 1) {
		if(head->next) head->next->prev = NULL;
		head = head->next;
		free(temp);
		return;
	}
	for(i=1;i<n;i++, temp=temp->next);
	if(!temp) {
		perror("Invalid position for deletion\n");
		return;
	}
	temp->prev->next = temp->next;
	if(temp->next) temp->next->prev = temp->prev;
	else tail = temp->prev;
	free(temp);
}

void aftersert(int data, int after) {
	if(!head) return;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(!newNode) {
		perror(memfail);
		return;
	}
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	struct Node *temp = head;
	for(;temp && temp->data != after;temp=temp->next);
	if(!temp) {
		perror(notfound);
		free(newNode);
		return;
	}
	newNode->prev = temp;
	if(temp->next) temp->next->prev = newNode;
	newNode->next = temp->next;
	if(!newNode->next) tail = newNode;
	temp->next = newNode;
}

void beforesert(int data, int before) {
	if(!head) return;
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(!newNode) {
		perror(memfail);
		return;
	}
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	if(head->data == before) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
 	struct Node *temp = head;
	for(;temp && temp->data != before;temp=temp->next);
	if(!temp) {
		perror(notfound);
		free(newNode);
		return;
	}
	temp->prev->next = newNode;
	newNode->prev = temp->prev;
	newNode->next = temp;
	temp->prev = newNode;
}

void display() {
	struct Node *temp = head;
	for(;temp;temp=temp->next) {
		printf("<- | %p | %d | %p | -> ", (void*)temp->prev, temp->data, (void*)temp->next);
	}
	printf("\n");
}

void display_rev() {
	struct Node *temp = tail;
	for(;temp;temp=temp->prev) {
		printf("<- | %p | %d | %p | -> ", (void*)temp->prev, temp->data, (void*)temp->next);
	}
	printf("\n");
}

int main() {
	int ch, ele, pos, after, before;
	printf("MENU\n");
	printf("%s", bar);
	printf("1. Append an element\n");
	printf("2. Delete last element\n");
	printf("3. Insert element at position\n");
	printf("4. Delete element at position\n");
	printf("5. Insert element after value\n");
	printf("6. Insert element before value\n");
	printf("7. Display the list\n");
	printf("8. Display the list in reverse order\n");
	printf("9. Exit\n");
	printf("%s", bar);
	scanf("%d", &ch);
	switch(ch) {
	case 1:
		printf("Enter element to append: ");
		scanf("%d", &ele);
		lastsert(ele);
		break;
	case 2:
		last_delete();
		break;
	case 3:
		printf("Enter element to insert: ");
		scanf("%d", &ele);
		printf("Enter position to insert at: ");
		scanf("%d", &pos);
		insert(pos, ele);
		break;
	case 4:
		printf("Enter position of element to delete: ");
		scanf("%d", &pos);
		delete(pos);
		break;
	case 5:
		printf("Enter element to insert: ");
		scanf("%d", &ele);
		printf("Enter element to insert after: ");
		scanf("%d", &after);
		aftersert(ele, after);
		break;
	case 6:
		printf("Enter element to insert: ");
		scanf("%d", &ele);
		printf("Enter element to insert before: ");
		scanf("%d", &before);
		beforesert(ele, before);
		break;
	case 7:
		display();
		break;
	case 8:
		display_rev();
		break;
	case 9:
		while(head) last_delete();
		return 0;
	default:
		printf("Invalid choice!\n");
	}
	main();
}
