#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to count the number of nodes in the loop starting from a given node
int countNodesInLoop(struct Node *list) {
    int count = 1;
    struct Node *temp = list;
    while (temp->next != list) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to detect and find the length of the loop
int findLengthOfLoop(struct Node* head) {
    struct Node *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;         // Move slow pointer by 1
        fast_p = fast_p->next->next;   // Move fast pointer by 2

        // If slow and fast meet, then there is a loop
        if (slow_p == fast_p) {
            return countNodesInLoop(slow_p);
        }
    }

    // If the loop finishes without meeting, there is no loop
    return 0; // Return 0 if no loop is found
}

// Main function to test the program
int main() {
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Create a loop for testing
    // 10 -> 15 -> 4 -> 20 -> 15 (loop starts at 15)
    head->next->next->next->next = head->next;

    int loop_length = findLengthOfLoop(head);

    if (loop_length > 0) {
        printf("Length of the loop is %d\n", loop_length);
    } else {
        printf("No loop found in the linked list\n");
    }

    // Note: Freeing memory for a linked list with a loop requires a different approach
    // to avoid infinite loops during traversal for free(). This program focuses on loop detection and length calculation.

    return 0;
}
