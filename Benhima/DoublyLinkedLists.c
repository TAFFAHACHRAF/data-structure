#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(int data){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  return newNode;
}

void insertAtBeginning(int data) {
  struct Node* newNode = createNode(data);
  if(head==NULL){
    head=newNode; return;
  }
  newNode->next=head;
  head->prev=newNode;
  head=newNode;
}

void insertAtEnd(int data) {
  struct Node* newNode = createNode(data);
  if(head==NULL){
    tail=newNode;
    head=newNode;
  }
  newNode->prev=tail;
  tail->next=newNode;
  tail=newNode;
}
void deleteHead() {
  if(head==NULL){
    printf("List is empty");
    return;
  }
  struct Node* temp = head->next;
  if (temp != NULL) {
    temp->prev = NULL;
  }
  head=temp;
}

void deleteTail() {
  if(tail==NULL){
    printf("List is empty");
    return;
  }
  struct Node* temp = tail->prev;
  if (temp != NULL) {
    temp->next = NULL;
  }
  tail=temp;
}

int searchValue(int value) {
  struct Node* temp = head;
  int position = 0;
  while (temp != NULL) {
    if (temp->data == value) {
      printf("Value %d found at position %d\n", value, position);
      return position;
    }
    temp = temp->next;
    position++;
  }
  printf("Value %d not found in the list\n", value);
  return -1;
}

int getLength() {
  int length = 0;
  struct Node* temp = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }
  return length;
}

void insertBeforePosition(int value, int position) {
  if(position<-1){
    printf("Invalid position");
    return;
  }else if(position == -1)
  {
    insertAtBeginning(value);
  }else if(position == getLength())
  {
    insertAtEnd(value);
  }else
  {
    struct Node* temp=head;
    struct Node* previous=NULL;
    int currentPosition = 0;
    while(temp != NULL && currentPosition != position){
      previous=temp;
      temp=temp->next;
      currentPosition++;
    }
    struct Node* newNode = createNode(value); 
    newNode->next = temp->next;
    previous->next = newNode;
    newNode->prev = previous;
    temp->prev = newNode;
    return;
  }
}

void insertAfterPosition(int value, int position) {
  if(position <= 0){
    printf("Invalid position");
    return;
  } else if(position == 1) {
    insertAtBeginning(value);
  } else if(position == getLength()+1) {
    insertAtEnd(value);
  } else {
    struct Node* temp = head;
    struct Node* after = NULL;
    int currentPosition = 0;
    while(temp != NULL && currentPosition != position){
      currentPosition++;
      temp = temp->next;
      after = temp->next;
    }
    struct Node* newNode = createNode(value); 
    newNode->next = after;
    after->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
  }
}

void deleteNode(int value) {
  if(head==NULL){
    printf("The list is empty");
    return;
  }
  int position = searchValue(value);
  if(position == -1){
    printf("The value doesn't exist in the list");
    return;
  }else{
    int currentPosition = 0;
    struct Node *temp = head;
    struct Node *prev = NULL;
    while(currentPosition != position){
      prev=temp;
      temp=temp->next;
      currentPosition++;
    }
    
    if (prev == NULL) {
      // The node to be deleted is the head node
      head = temp->next;
      head->prev = NULL;
    } else {
      prev->next = temp->next;
      if (temp->next != NULL) {
        temp->next->prev = prev;
      }
    }    
    free(temp);
    printf("Node with value %d deleted\n", value);
  }
}

void printList() {
  struct Node* temp = head;
  while(temp != NULL){
    printf("->%d",temp->data);
    temp=temp->next;
  }
}
int main() {
  struct Node* head = NULL;
  struct Node* tail = NULL;
  // Test the linked list operations
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);

  printf("Linked list: ");
  printList();  // Output: ->1->2->3

  printf("\n");

  searchValue(2);  // Output: Search 2: Found
  searchValue(4);  // Output: Search 4: Not found

  printf("\n");

  deleteHead();
  printf("Linked list after deleting head: ");
  printList();  // Output: ->2->3

  printf("\n");

  deleteTail();
  printf("Linked list after deleting tail: ");
  printList();  // Output: ->2

  printf("\n");

  insertAfterPosition(4, 1);
  printf("Linked list after inserting 4 at position 1: ");
  printList();  // Output: ->2->4

  printf("\n");

  insertAfterPosition(5, 2);
  printf("Linked list after inserting 5 at position 2: ");
  printList();  // Output: ->2->4->5

  printf("\n");
  
  insertBeforePosition(6, 2);
  printf("Linked list after inserting 4 at position 1: ");
  printList();  // Output: ->2->4->6->5

  printf("\n");
  return 0;
}
