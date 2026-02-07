#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node
typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(const char *str) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;

    // Duplicate the string onto the heap
    newNode->data = strdup(str);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. INSERT: Adds to the end of the list
void insertEnd(Node **head, const char *str) {
    Node *newNode = createNode(str);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// 2. FIND: Returns node if string matches, else NULL
Node* findNode(Node *head, const char *str) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, str) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

// 3. DELETE: Removes a specific node and frees memory
void deleteNode(Node **head, Node *del) {
    if (*head == NULL || del == NULL) return;

    // If node to be deleted is head node
    if (*head == del) *head = del->next;

    // Change next only if node to be deleted is NOT the last node
    if (del->next != NULL) del->next->prev = del->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL) del->prev->next = del->next;

    // Free the string buffer and then the node
    free(del->data);
    free(del);
}

// Helper to print the list
void printList(Node *head) {
    printf("List: ");
    while (head != NULL) {
        printf("[%s] <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Hello World!\n");
    Node *head = NULL;

    insertEnd(&head, "Apple");
    insertEnd(&head, "Banana");
    insertEnd(&head, "Cherry");
    printList(head);

    printf("\n--- Testing Find ---\n");
    Node *found = findNode(head, "Banana");
    if (found) printf("Found: %s\n", found->data);

    printf("\n--- Testing Deletion (Banana) ---\n");
    deleteNode(&head, found);
    printList(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        deleteNode(&head, head);
    }

    return 0;
}