#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct Node {
    int data;
    struct Node* next;
};

/**
 * Function to detect a loop in a linked list using Floyd's Cycle Detection Algorithm.
 * 
 * @param head The head of the linked list.
 * @return 1 if a loop is detected, 0 otherwise.
 */
int detectCycle(struct Node* head) {
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL) {
        // Move slow pointer by one step
        slow_ptr = slow_ptr->next;
        // Move fast pointer by two steps
        fast_ptr = fast_ptr->next->next;

        // If slow and fast pointers meet, then there is a loop
        if (slow_ptr == fast_ptr) {
            return 1; // Loop found
        }
    }
    return 0; // No loop found
}

/**
 * Utility function to create a new node.
 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Driver program to test the function
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Case 1: No loop
    if (detectCycle(head)) {
        printf("Case 1: Loop detected\n");
    } else {
        printf("Case 1: No loop detected\n");
    }

    // Case 2: Create a loop (make 5 point to 3)
    // List becomes: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop)
    head->next->next->next->next->next = head->next->next; 

    if (detectCycle(head)) {
        printf("Case 2: Loop detected\n");
    } else {
        printf("Case 2: No loop detected\n");
    }
    
    // Note: In a real-world scenario, you should free the allocated memory.
    // However, with a loop present, manual memory management becomes complex 
    // without first breaking the loop or using a garbage collector.

    return 0;
}
