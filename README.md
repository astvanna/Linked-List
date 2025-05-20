# Linked-List
Node* createNode(int value)
Purpose: Create and initialize a new node.

void insertAtEnd(Node **head, int value)
Purpose: Add a new node with value to the end of the list.

void insertAtFront(Node **head, int value)
Purpose: Add a new node with value to the front of the list.

void insertAt(Node **head, int index, int value)
Purpose: Add a new node with value at the specified position (0-based index).

void deleteNode(Node **head, int value)
Purpose: Remove the first node with the specified value.

void removeFront(Node **head)
Purpose: Remove the first node in the list.

void removeBack(Node **head)
Purpose: Remove the last node in the list.

void removeAt(Node **head, int index)
Purpose: Remove the node at the specified position (0-based index).

Node *search(Node *head,int val)
Purpose: Returns the first node pointer with value equals val, NULL if there is none

void printList(Node *head)
Purpose: Print all the values in the linked list.

void freeList(Node **head)
Purpose: Free all the nodes in the list.
