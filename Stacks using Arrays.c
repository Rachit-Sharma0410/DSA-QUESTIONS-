#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1; /

void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

void peep() {
    if (top == -1) {
        printf("Stack is empty! Nothing to peep.\n");
    } else {
        printf("Top element is %d.\n", stack[top]);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty! Nothing to display.\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {

        printf("\nStack Operations:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: display(); break;
            case 5: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
