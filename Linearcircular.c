#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Function declarations
void insert();
void delete();
int getFront();
int getRear();
int isFull();
int isEmpty();
void viewQueue();
void exitProgram();

// Global variables
int queue[MAX];
int front = -1;
int rear = -1;

int main() {
    int choice;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Get Front\n");
        printf("4. Get Rear\n");
        printf("5. Is Full\n");
        printf("6. Is Empty\n");
        printf("7. View Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                printf("Front element: %d\n", getFront());
                break;
            case 4:
                printf("Rear element: %d\n", getRear());
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 7:
                viewQueue();
                break;
            case 8:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// Function to insert an element in the queue
void insert() {
    int value;
    if (isFull()) {
        printf("Queue is full. Insertion is not possible.\n");
    } else {
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void delete() {
    if (isEmpty()) {
        printf("Queue is empty. Deletion is not possible.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Function to get the front element of the queue
int getFront() {
    if (!isEmpty()) {
        return queue[front];
    } else {
        printf("Queue is empty.\n");
        return -1;
    }
}

// Function to get the rear element of the queue
int getRear() {
    if (!isEmpty()) {
        return queue[rear];
    } else {
        printf("Queue is empty.\n");
        return -1;
    }
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to view all elements in the queue
void viewQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to exit the program
void exitProgram() {
    printf("Exiting the program.\n");
    exit(0);
}
