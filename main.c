#include "node.h"
#include <stdio.h>

int main() {
	Node* head = NULL;
	
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	printList(head);
	
	insertAtFront(&head, 5);
	printList(head);
	
	insertAt(&head, 1, 15);
	printList(head);
	
	deleteNode(&head, 15);
	printList(head);
	
	removeFront(&head);
	printList(head);
	
	removeBack(&head);
	printList(head);
	
	removeAt(&head, 0);
	printList(head);
	
	freeList(&head);
	
	return 0;
}
