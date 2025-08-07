#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char name[50];
    struct Task* next;
} Task;

Task* taskQueue = NULL; // FIFO - Queue Front
Task* queueRear = NULL; // Queue Rear
Task* undoStack = NULL; // LIFO - Stack Top

// Queue: Add to rear
void enqueue(char* taskName) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, taskName);
    newTask->next = NULL;

    if (taskQueue == NULL) {
        taskQueue = queueRear = newTask;
    } else {
        queueRear->next = newTask;
        queueRear = newTask;
    }

    printf("Task added: %s\n", taskName);
}

// Queue: Remove from front
void dequeue() {
    if (taskQueue == NULL) {
        printf("No tasks to complete.\n");
        return;
    }

    Task* temp = taskQueue;
    printf("Task completed: %s\n", temp->name);
    taskQueue = taskQueue->next;

    if (taskQueue == NULL) {
        queueRear = NULL;
    }

    free(temp);
}

// Stack: Push on top
void pushUndo(char* taskName) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, taskName);
    newTask->next = undoStack;
    undoStack = newTask;
}

// Stack: Pop from top and remove from queue (if still there)
void undoLast() {
    if (undoStack == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    char taskToUndo[50];
    strcpy(taskToUndo, undoStack->name);

    // Pop from undo stack
    Task* tempUndo = undoStack;
    undoStack = undoStack->next;
    free(tempUndo);

    // Remove matching task from queue (only first match)
    Task* prev = NULL;
    Task* curr = taskQueue;

    while (curr != NULL) {
        if (strcmp(curr->name, taskToUndo) == 0) {
            if (prev == NULL) {
                taskQueue = curr->next;
            } else {
                prev->next = curr->next;
            }

            // Adjust rear if needed
            if (curr == queueRear) {
                queueRear = prev;
            }

            free(curr);
            printf("Undo successful. Removed task: %s\n", taskToUndo);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Task already completed. Cannot undo: %s\n", taskToUndo);
}

// Display tasks in the queue
void showTasks() {
    if (taskQueue == NULL) {
        printf("No tasks in the queue.\n");
        return;
    }

    Task* temp = taskQueue;
    printf("Pending Tasks:\n");
    int count = 1;
    while (temp != NULL) {
        printf("%d. %s\n", count++, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char task[50];

    do {
        printf("\n1. Add Task\n2. View Tasks\n3. Complete Task\n4. Undo Last Add\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Task: ");
                fgets(task, sizeof(task), stdin);
                task[strcspn(task, "\n")] = 0; // remove newline
                enqueue(task);
                pushUndo(task);
                break;
            case 2:
                showTasks();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                undoLast();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
