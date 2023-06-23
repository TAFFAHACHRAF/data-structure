#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *createList(struct node *start);
void displayList(struct  node *start);
void countList(struct node *start);
struct node *insertInBegining(struct node *start,int data);
struct node *insertAtEnd(struct node *start,int data);
void search(struct node *start);


struct node *createList(struct node *start){
    int n,data,i;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    if(n==0) 
        return start; 
    
    printf("Entre : ");
    scanf("%d",&data);

    start=insertInBegining(start,data); 

    for(i=2;i<=n;i++){ 
        printf("Enter : ");
        scanf("%d",&data);
        insertAtEnd(start,data);
    }
    return start;
}

void displayList(struct  node *start){
    struct node *p;
    if(start->link == NULL){
        printf("List is empty \n");
    }
    p=start;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->link;
    }
    printf("\n");
}

void countList(struct node *start){
    int count=0;
    struct node *p=start;
    while(p != NULL){
        count++;
        p=p->link;
    }
    printf("This liste contains %d elements.",count);
}
 
//Head --> first element
//Tail --> last element

struct node *insertInBegining(struct node *start,int data){
    struct node *temp;
    temp->data=data;
    temp->link=start;
    // start=temp;
    return temp;
}

struct node *insertAtEnd(struct node *start,int data){
    struct node *p,*temp;
    temp->data=data;

    p=start;
    while(p->link != NULL)  
        p=p->link;
    p->link = temp;
    temp->link=NULL;

    // return temp
    start=temp;
    return start;
}





//THE MAIN CODE : 
int main(){
  
 ;
  int  choice, temp;
  struct node *First;
  printf("HI WELCOME HOME !!!\n WHAT DO YOU WANT : ?");
  printf("\n1-START THE LINKED LIST? PLEASE (1)") ;
  printf(" \n2-ADD NEW NUMBER ? PLEASE (2)");
  printf("\n3-GET TO KNOW THE SIZE OF THE LINKED LIST? PLEASE(3)");
  scanf("%d",&choice);
  switch(choice){
  	case 1: 
	   printf("give us the value that u want to start the list with!");
  	scanf("%d",&temp);
  	printf("\n");
  	displayList(insertInBegining(First,temp));
  	break;
  	case 3: printf("The size of the list is : ");
  	countList(First);
  	break;
  	default: printf("please give us your choice!!!");
  }
  
  
  
  
  
  
  
  
  
  
  
}
