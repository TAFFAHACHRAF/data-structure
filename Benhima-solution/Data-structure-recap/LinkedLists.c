#include <stdio.h>
#include <stdlib.h>

//Singly linked lists
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->next=NULL;
	newNode->data=data;
	return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data){
	struct Node* newNode = createNode(data);
	if(head==NULL){
		return newNode;
	}else{
		newNode->next=head;
		return newNode;
	}
}
struct Node* insertAtEnd(struct Node* head, int data){
	struct Node* newNode = createNode(data);
	if(head==NULL){
		return newNode;
	}else{
		struct Node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	return head;
}
int searchElement(struct Node* head, int data){
	struct Node* temp=head;
	while(temp!=NULL){
		if(temp->data==data)
			return 1;
		temp=temp->next;
	}
	return 0;
}
void displayLinkedList(struct Node* head){
	if(head==NULL){
		printf("Liste vide");
	}else{
		struct Node* temp=head;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}
}
struct Node* deleteNode(struct Node* head, int data){
	if(head==NULL){
		printf("Liste vide");
		return head;
		}
	if(searchElement(head,data)==0){
		printf("Element non existant");
		return head;
	}else{
		if(head->data==data){
			head=head->next;
			return head;
		}else{
		struct Node* temp=head;
		struct Node* prev=NULL;
		while(temp!=NULL){
			prev=temp;
			if(temp->data==data){
				prev->next=temp->next;
				free(temp);
				return head;
				}
			temp=temp->next;
			}
		}
	}
}

struct Node* insertAfterNode(struct Node* head,struct Node* prevNode, int data){
	if(head==NULL){
		printf("Liste vide");
		return head;
	}
	struct Node* newNode=createNode(data);
	if(prevNode==head){
		newNode->next=head->next;
		head->next=newNode;
		return head;
	}else{
		struct Node* temp=head->next;
		while(temp!=NULL){
			if(temp==prevNode){
				newNode->next=prevNode->next;
				prevNode->next=newNode;
				return head;
			}
			temp=temp->next;
		}
	}
}

//Doubly linked lists

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->prev=NULL;
	newNode->next=NULL;
	newNode->data=data;
	return newNode;
}
struct Node* insertAtBeginning(struct Node* head, int data){
	struct Node* newNode = createNode(data);
	if(head==NULL){
		return newNode;
	}else{
		newNode->next=head;
		head->prev=newNode;
		return newNode;
	}
}
struct Node* insertAtEnd(struct Node* tail, int data){
	struct Node* newNode = createNode(data);
	if(tail==NULL){
		return newNode;
	}else{
		newNode->prev=tail;
		tail->next=newNode;
		return newNode;
	}
}
int searchElement(struct Node* head, int data){
	struct Node* temp=head;
	while(temp!=NULL){
		if(temp->data==data)
			return 1;
		temp=temp->next;
	}
	return 0;
}
void displayForward(struct Node* head){
	if(head==NULL){
		printf("Liste vide");
	}else{
		struct Node* temp=head;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}
}
void displayBackward(struct Node* tail){
	if(tail==NULL){
		printf("tail nul");
	}else{
		struct Node* temp=tail;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->prev;
		}
	}
}
struct Node* deleteNode(struct Node* head, int data){
	if(head==NULL){
		printf("Liste vide");
		return head;
		}
	if(searchElement(head,data)==0){
		printf("Element non existant");
		return head;
	}else{
		if(head->data==data){
			head=head->next;
			return head;
		}else{
		struct Node* temp=head;
		while(temp!=NULL){
			if(temp->data==data){
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
				return head;
				}
			temp=temp->next;
			}
		}
	}
}
struct Node* insertAfterNode(struct Node* head,struct Node* prevNode, int data){
	if(head==NULL){
		printf("Liste vide");
		return head;
	}
	struct Node* newNode=createNode(data);
	if (prevNode == NULL) {
        printf("Previous node cannot be NULL");
        free(newNode);
        return head;
    }
	if(prevNode==head){
		newNode->next=head->next;
		newNode->prev=head;
		if (head->next != NULL)
            head->next->prev = newNode;
		head->next=newNode;
		return head;
	}
		struct Node* temp=next;
		while(temp!=NULL){
			if(temp==prevNode){
				newNode->next=prevNode->next;
				newNode->prev=prevNode;
				if (prevNode->next != NULL)
                	prevNode->next->prev = newNode;
				prevNode->next=newNode;
				return head;
			}
			temp=temp->next;
		}
	printf("Previous node not found");
    free(newNode);
    return head;
}
