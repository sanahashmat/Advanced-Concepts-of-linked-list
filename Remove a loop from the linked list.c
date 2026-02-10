#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove the loop
void removeTheLoop(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;

    // Phase 1: Detect the loop and find the meeting point
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            break; // Loop detected
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    /* If loop exists (the pointers met) */
    if (slow == fast) {
        slow = head;
        // Phase 2: Find the loop starting point and break the loop

        // Case 1: The meeting point is the head of the list
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL; // Break the loop
        }
        // Case 2: The starting point of the loop is somewhere in the middle
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            // 'fast' now points to the node just before the loop starting node
            // 'slow' also points to the node just before the loop starting node
            fast->next = NULL; // Break the loop
        }
    }
}

// Helper function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Helper function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver Code
int main() {
    /* Create a linked list: 1->2->3->4->5->NULL */
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    /* Create a loop: Make 5 point to 3 */
    head->next->next->next->next->next = head->next->next;

    printf("Linked List before removing loop (if you try to print this, it will loop indefinitely).\n");

    /* Remove the loop */
    removeTheLoop(head);

    printf("Linked List after removing loop: ");
    printList(head); // Should print 1 2 3 4 5

    return 0;
}
