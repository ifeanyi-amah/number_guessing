#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char name[50];
    struct Task* next;
} Task;

Task* taskQueue = NULL; // FIFO queue for task list
Task* undoStack = NULL; // LIFO stack for undoing last add

// Add a task to the end of the queue
void enqueue(char* taskName) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, taskName);
    newTask->next = NULL;

    if (taskQueue == NULL) {
        taskQueue = newTask;
    } else {
        Task* temp = taskQueue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }
    printf("Task added: %s\n", taskName);
}

// Remove task from the front of the queue
void dequeue() {
    if (taskQueue == NULL) {
        printf("No tasks to complete.\n");
        return;
    }
    Task* temp = taskQueue;
    taskQueue = taskQueue->next;
    printf("Task completed: %s\n", temp->name);
    free(temp);
}

// Push a task onto the undo stack
void pushUndo(char* taskName) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, taskName);
    newTask->next = undoStack;
    undoStack = newTask;
}

// Undo last added task (remove from queue)
void undoLast() {
    if (undoStack == NULL || taskQueue == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    // Get task to remove
    char undoTaskName[50];
    strcpy(undoTaskName, undoStack->name);

    // Remove from undo stack
    Task* tempUndo = undoStack;
    undoStack = undoStack->next;
    free(tempUndo);

    // Remove from queue (from tail to head — tricky!)
    Task* current = taskQueue;
    Task* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, undoTaskName) == 0) {
            if (prev == NULL) {
                // Removing head
                taskQueue = current->next;
            } else {
                prev->next = current->next;
            }
            printf("Undid task: %s\n", undoTaskName);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Task not found in queue.\n");
}

// Display all current tasks
void showTasks() {
    if (taskQueue == NULL) {
        printf("No tasks in queue.\n");
        return;
    }
    Task* temp = taskQueue;
    printf("Task List:\n");
    int count = 1;
    while (temp != NULL) {
        printf("%d. %s\n", count++, temp->name);
        temp = temp->next;
    }
}

// Main program
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
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}