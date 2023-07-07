#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int estVide(struct Node* head) {
    return head == NULL;
}

int tete(struct Node* head) {
    if (estVide(head)) {
        printf("Err pile vide");
        exit(0);
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }
}

struct Node* enfiler(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (estVide(head)) {
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

struct Node* defiler(struct Node* head) {
    if (estVide(head)) {
        printf("Err: vide");
        exit(0);
    } else {
        printf("%d\n", head->data);
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Enqueue some elements
    head = enfiler(head, 10);
    head = enfiler(head, 20);
    head = enfiler(head, 30);
    
    // Dequeue elements
    head = defiler(head);
    head = defiler(head);
    head = defiler(head);
    
    // Empty queue
    head = defiler(head); 
    
    return 0;
}
