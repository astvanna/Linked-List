#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int value) {
	Node* new = malloc(sizeof(Node));
	if (!new) return NULL;
	
	new->val = value;
	new->next = NULL;
	return new;
}

void insertAtEnd(Node **head, int value) {
	if (!head) return;
	
	Node* new = createNode(value);
	if (!new) return;
	
	if (!*head) {
		*head = new;
		return;
	}
	
	Node* current = *head;
	while (current->next) {
		current = current->next;
	}
	current->next = new;
}

void insertAtFront(Node **head, int value) {
	if (!head) return;
	
	Node* new = createNode(value);
	if (!new) return;
	
	new->next = *head;
	*head = new;
}

void insertAt(Node **head, int index, int value) {
	if (!head || index < 0) return;
	
	if (!index) {
		insertAtFront(head, value);
		return;
	}
	
	Node* new = createNode(value);
	if (!new) return;
	
	Node* current = *head;
	for (int i = 0; current && i < index - 1; i++) {
		current = current->next;
	}
	
	if (!current) {
		free(new);
		return;
	}
	
	new->next = current->next;
	current->next = new;
}

void deleteNode(Node **head, int value) {
	if (!head || !*head) return;
	
	Node *temp = *head, *prev = NULL;
	
	if (temp->val == value) {
		*head = temp->next;
		free(temp);
		return;
	}
	
	while (temp && temp->val != value) {
		prev = temp;
		temp = temp->next;
	}
	
	if (!temp) return;
	
	prev->next = temp->next;
	free(temp);
}

void removeFront(Node **head) {
	if (!head || !*head) return;
	
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void removeBack(Node **head) {
	if (!head || !*head) return;
	
	if (!(*head)->next) {
		free(*head);
		*head = NULL;
		return;
	}
	
	Node* current = *head;
	while (current->next->next) {
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
}

void removeAt(Node **head, int index) {
	if (!head || !*head || index < 0) return;
	
	if (!index) {
		removeFront(head);
		return;
	}
	
	Node* current = *head;
	for (int i = 0; current && i < index - 1; i++) {
		current = current->next;
	}
	
	if (!current || !current->next) return;
	
	Node* temp = current->next;
	current->next = temp->next;
	free(temp);
}

Node* search(Node *head, int val) {
	Node* current = head;
	while (current) {
		if (current->val == val) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void printList(Node *head) {
	if (!head) {
		printf("List is empty.\n");
		return;
	}
	
	Node* current = head;
	while (current) {
		printf("%d", current->val);
		if (current->next) {
			printf(" ");
		}
		current = current->next;
	}
	printf("\n");
}

void freeList(Node **head) {
	if (!head) return;
	
	Node *current = *head, *next;
	while (current) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
