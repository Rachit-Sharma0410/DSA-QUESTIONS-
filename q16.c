#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtFront(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the front.\n", value);
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (tail == NULL) {

        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}
void deleteLastNode() {
    if (tail == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted last node with value %d.\n", temp->data);
    free(temp);
}
void deleteNodeBeforePosition(int pos) {
    if (head == NULL || pos <= 1) {
        printf("Invalid position or list is too short.\n");
        return;
    }

    struct Node* current = head;
    int count = 1;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->prev == NULL) {
        printf("No node to delete before position %d.\n", pos);
        return;
    }

    struct Node* temp = current->prev;
    if (temp->prev != NULL) {
        temp->prev->next = current;
        current->prev = temp->prev;
    } else {
        head = current;
        current->prev = NULL;
    }

    printf("Deleted node before position %d with value %d.\n", pos, temp->data);
    free(temp);
}
void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete last node\n");
        printf("4. Delete node before position\n");
        printf("5. Traverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteLastNode();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteNodeBeforePosition(pos);
                break;
            case 5:
                traverseList();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
