#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int estVide(struct Node* head) {
    return head == NULL;
}

int sommet(struct Node* head) {
    if (estVide(head)) {
        printf("Err pile vide");
        exit(0);
    } else {
        return head->data;
    }
}

struct Node* empiler(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (estVide(head) == 1)
        return newNode;
    else {
        newNode->next = head;
        return newNode;
    }
}

struct Node* depiler(struct Node* head) {
    if (estVide(head) == 1) {
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

    // Test empiler function
    head = empiler(head, 1);
    head = empiler(head, 2);
    head = empiler(head, 3);

    // Test sommet function
    printf("Sommet: %d\n", sommet(head));

    // Test depiler function
    head = depiler(head);
    head = depiler(head);
    head = depiler(head);

    // Test estVide function
    printf("Is empty? %s\n", estVide(head) ? "Yes" : "No");

    return 0;
}
