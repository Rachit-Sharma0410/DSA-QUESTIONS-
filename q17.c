#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;  
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  
    }
    printf("Inserted %d at the end.\n", value);
}
void insertBeforePosition(int value, int pos) {
    struct Node* newNode = createNode(value);
    if (head == NULL || pos == 1) {
        printf("Cannot insert before position 1 or empty list.\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && pos != count + 1) {
        printf("Position is out of range.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d before position %d.\n", value, pos);
}
void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    if (head->next == head) {
    
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head; 
    }
    printf("Deleted first node with value %d.\n", temp->data);
    free(temp);
}
void deleteNodeAfterPosition(int pos) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp->next != head && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        printf("Position is out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == head) {
        head = delNode->next;
    }

    printf("Deleted node after position %d with value %d.\n", pos, delNode->data);
    free(delNode);
}
void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert before position\n");
        printf("3. Delete first node\n");
        printf("4. Delete node after position\n");
        printf("5. Traverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position before which to insert: ");
                scanf("%d", &pos);
                insertBeforePosition(value, pos);
                break;
            case 3:
                deleteFirstNode();
                break;
            case 4:
                printf("Enter position after which to delete: ");
                scanf("%d", &pos);
                deleteNodeAfterPosition(pos);
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
