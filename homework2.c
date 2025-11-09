#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Cunction prototypes
void insertSorted(struct Node** head, int value);
void printList(struct Node* head);
void freeList(struct Node* head);

int main() {
    int series[] = {999, 111, 666, 444, 222, 888, 333, 555, 777};
    int n = sizeof(series)/sizeof(series[0]);

    struct Node* head = NULL;

    printf("Inserting numbers into the linked list:\n");
    for(int i = 0; i < n; i++) {
        insertSorted(&head, series[i]);
        printList(head);
        printf("\n");
    }

    printf("Final sorted list:\n");
    printList(head);

    freeList(head);
    return 0;
}

// Insert in ascending order
void insertSorted(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Print the list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
