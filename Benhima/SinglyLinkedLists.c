#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* createNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->next=NULL;
  newNode->data=data;
  return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next=head;
  return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
  struct Node* newNode = createNode(data);
  if(head == NULL){
    return newNode;
  }
  struct Node* temp = head;
  while(temp->next != NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return head;
}

struct Node* insertAfterPosition(struct Node* head, int data, int position){
  if(head==NULL){
    printf("List is empty");
    return head;
  }
  struct Node* newNode=createNode(data);
  struct Node* temp=head;
  int counter=0;
  while(temp!=NULL){
    if(counter==position){
      struct Node* temp2=temp->next;
      temp->next=newNode;
      newNode->next=temp2;
      return head;
    }
    temp=temp->next;
    counter++;
  }
  printf("Position doesn't exist"); 
  return head;
}
struct Node* insertBeforePosition(struct Node* head, int data, int position){
  if(head==NULL||position==0){
    printf("List is empty or invalid position");
    return head;
  }
  if(position==1){
    insertAtBeginning(head,data);
  }
  struct Node* newNode=createNode(data);
  struct Node* temp=head;
  int counter=0;
  while(temp!=NULL){
    if(counter==position-1){
      struct Node* temp2=temp->next;
      temp->next=newNode;
      newNode->next=temp2;
      return head;
    }
    temp=temp->next;
    counter++;
  }
  printf("Position doesn't exist"); 
  return head;
}
//2nd implementation
struct Node* insertBeforePosition2nd(struct Node* head, int data, int position) {
  struct Node* newNode = createNode(data);
  if (position == 0) {
    newNode->next = head;
    return newNode;
  }
  struct Node* temp = head;
  int currentPosition = 0;
  while (temp != NULL && currentPosition < position - 1) {
    if (currentPosition == position - 2) {
      newNode->next = temp->next;
      temp->next = newNode;
      return head;
    }
    temp = temp->next;
    currentPosition++;
  }
  printf("Invalid position\n");
  return head;
}

int searchValue(struct Node* head, int value) {
  struct Node* temp = head;
  int position = 0;
  while (temp != NULL) {
    if (temp->data == value) {
      printf("%d exists in the list at position %d\n", value, position);
      return position;
    }
    temp = temp->next;
    position++;
  }
  printf("%d doesn't exist in the list\n", value);
  return -1;  // Return -1 if the value is not found
}

void printList(struct Node* head) {
  struct Node* temp= head;
  while(temp != NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

struct Node* deleteNode(struct Node* head, int value) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }
  int position = searchValue(head,value);
  if (position == -1){
    printf("The value doesn't exist in the list \n");
    return head;
  }
  struct Node* temp = head;
  struct Node* prev = NULL;
  int currentPosition = 0;
  while (currentPosition != position) {
    prev=temp;
    temp = temp->next;
    currentPosition++;
  }
  if (prev == NULL) {
    // The node to be deleted is the head node
    head = temp->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
  printf("Node with value %d deleted\n", value);
  return head;
}

//2nd implementation
struct Node* deleteNode2nd(struct Node* head, int value) {
  if (head == NULL) {
    printf("List is empty\n");
    return NULL;
  }
  struct Node* temp = head;
  struct Node* prev = NULL;
  // Check if the value to be deleted is in the head Node
  if (temp != NULL && temp->data == value) {
    head = temp->next;
    free(temp);
    printf("Node with value %d deleted\n", value);
    return head;
  }
  // Search for the Node with the value to be deleted
  while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }
  // If the value was not found in the list
  if (temp == NULL) {
    printf("Node with value %d not found\n", value);
    return head;
  }
  // Remove the Node from the list
  prev->next = temp->next;
  free(temp);
  printf("Node with value %d deleted\n", value);
  return head;
}

int getLength(struct Node* head) {
  int length = 0;
  struct Node* temp = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }
  return length;
}

int main() {
  struct Node* head = NULL;

  // Insert nodes at the beginning
  head = insertAtBeginning(head, 2);
  head = insertAtBeginning(head, 1);
  head = insertAtBeginning(head, 0);
  printList(head);  // Output: 0->1->2->

  // Insert nodes at the end
  head = insertAtEnd(head, 3);
  head = insertAtEnd(head, 4);
  printList(head);  // Output: 0->1->2->3->4->

  // Insert node after a position
  head = insertAfterPosition(head, 10, 2);
  printList(head);  // Output: 0->1->2->10->3->4->

  // Insert node before a position
  head = insertBeforePosition(head, 20, 3);
  printList(head);  // Output: 0->1->2->20->10->3->4->

  // Search for values
  searchValue(head, 2);   // Output: 2 exists in the list
  searchValue(head, 100); // Output: 100 doesn't exist in the list

  // Delete nodes
  head = deleteNode(head, 2);
  printList(head);  // Output: 0->1->20->10->3->4->

  head = deleteNode(head, 100);  // Trying to delete a non-existent Node
  printList(head);  // Output: 0->1->20->10->3->4->

  return 0;
}
