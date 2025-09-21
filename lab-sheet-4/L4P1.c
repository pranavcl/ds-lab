#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void beforesert(int val, int before) {
	struct Node *newNode = createNode(val);
	if (head == NULL || head->data == before) {
		newNode->next = head;
		head = newNode;
		return;
	}
	struct Node *curr = head;
	while (curr->next != NULL && curr->next->data != before)
		curr = curr->next;
	if (curr->next != NULL) {
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void aftersert(int val, int after) {
	struct Node *curr = head;
	while (curr != NULL && curr->data != after)
		curr = curr->next;
	if (curr != NULL) {
		struct Node *newNode = createNode(val);
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void delete(int val) {
	if (head == NULL) return;
	if (head->data == val) {
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return;
	}
	struct Node *curr = head;
	while (curr->next != NULL && curr->next->data != val)
		curr = curr->next;
	if (curr->next != NULL) {
		struct Node *temp = curr->next;
		curr->next = temp->next;
		free(temp);
	}
}

void display() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *curr = head;
	printf("Linked list: ");
	while (curr != NULL) {
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}

void reverse() {
	struct Node *prev = NULL, *curr = head, *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void sort() {
	if (head == NULL) return;
	int swapped, temp;
	struct Node *ptr, *lptr = NULL;
	do {
		swapped = 0;
		ptr = head;
		while (ptr->next != lptr) {
			if (ptr->data > ptr->next->data) {
				temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	} while (swapped);
}

void delete_alternate() {
	if (head == NULL) return;
	struct Node *curr = head->next, *prev = head;
	while (curr != NULL) {
		prev->next = curr->next;
		free(curr);
		prev = prev->next;
		if (prev == NULL) break;
		curr = prev->next;
	}
}

void sortsert(int val) {
	struct Node *newNode = createNode(val);
	if (head == NULL || head->data >= val) {
		newNode->next = head;
		head = newNode;
		return;
	}
	struct Node *curr = head;
	while (curr->next != NULL && curr->next->data < val)
		curr = curr->next;
	newNode->next = curr->next;
	curr->next = newNode;
}

int main() {
	int choice, val, key, i;
	while (1) {
		printf("\nMenu:\n");
		printf("1. Insert before\n2. Insert after\n3. Delete\n4. Display\n5. Reverse\n6. Sort\n7. Delete alternate\n8. Insert sorted\n9. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value and element to insert before: ");
				scanf("%d %d", &val, &key);
				beforesert(val, key);
				break;
			case 2:
				printf("Enter value and element to insert after: ");
				scanf("%d %d", &val, &key);
				aftersert(val, key);
				break;
			case 3:
				printf("Enter value to delete: ");
				scanf("%d", &val);
				delete(val);
				break;
			case 4:
				display();
				break;
			case 5:
				reverse();
				break;
			case 6:
				sort();
				break;
			case 7:
				delete_alternate();
				break;
			case 8:
				printf("Enter value to insert in sorted list: ");
				scanf("%d", &val);
				sortsert(val);
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
