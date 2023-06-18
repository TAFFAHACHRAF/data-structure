#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}node;
node* ReservationMemoir(){
	node* n;
	return  n=(struct node*)malloc(sizeof(struct node));
}
 node* getNewNode(int data){	
 node *NewNode= ReservationMemoir();
NewNode->data=data;
NewNode->prev=NULL;
NewNode->next=NewNode;
return NewNode;
}

 node* insert_at_head(int value,node *OldHead){
	 node *NewNode=getNewNode(value);
	 OldHead->next=NULL;
	 OldHead->prev=NewNode;
	 NewNode->next=OldHead;
	 return NewNode;
}
node* insert_at_tail(int value,node *OldTail){
	node *NewNode=getNewNode(value);
	OldTail->next=NewNode;
	NewNode->prev=OldTail;
	NewNode->next=NULL;
	return NewNode;
}
void insert_at_middle(int value, int position,node* Node){
//what is the  position!!!!
	
}

void printLinkedListForward(node* NODE){
	if(NODE->next==NULL){
		printf("Data = %d",NODE->data);
	}
	else {
	
     	while(NODE->next!=NULL){
	    	printf("Data = %d\n",NODE->data);
	    	NODE->next=NODE->next;
    	}
	}
}
void printLinkedListBackward(node* NODE){
	if(NODE->prev==NULL){
		printf("Data = %d",NODE->data);
	}
	else {
	
     	while(NODE->prev!=NULL){
	    	printf("Data = %d\n",NODE->data);
	    	NODE->prev=NODE->prev;
    	}
	}
}

void main(){
	
}
