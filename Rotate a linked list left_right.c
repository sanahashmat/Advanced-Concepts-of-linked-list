#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* new_node = 
       (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct Node* rotate(struct Node *head, int k) {
    if (k == 0 || head == NULL)
        return head;

    // rotate the list by k nodes
    for (int i = 0; i < k; ++i) {
        struct Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        // move the first node to the last
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d", node->data);
        if(node->next != NULL){
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {

    struct Node *head = createNode(10);
	head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
  
    head = rotate(head, 6);
    printList(head);

    return 0;
}