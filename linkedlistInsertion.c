#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

//Function to traverse
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

//Function to insert at the beginning
struct Node * insertAtFirst(struct Node *head, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    
    return ptr;
}

//Function to insert at the end
struct Node * insertAtEnd(struct Node *head, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while (p -> next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}    

//Function to insert after a node
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
   
    return head;
}    

//Function to insert in between
struct Node * insertAtIndex(struct Node *head, int data, int index) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main() {
 
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 5;
    second->next = third;

    //Link third and fourth nodes
    third->data = 23;
    third->next = fourth;

    //Link fourth and last nodes
    fourth->data = 9;
    fourth->next = NULL;
    
    printf("Linked list before insertion: \n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 22);
    // head = insertAtIndex(head, 78, 3);
    head = insertAtEnd(head, 47);
    //head = insertAfterNode(head, third, 65);
    printf("\nLinked list after insertion: \n");
    linkedListTraversal(head);
    

    return 0;
}