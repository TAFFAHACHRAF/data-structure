#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Element{
	int data;
	struct Element *left;
	struct Element *right;
}Element;

Element* createElement(int data){
	Element* E=(Element*)malloc(sizeof(Element));
	E->data=data;
	E->left=NULL;
	E->right=NULL;
	return E;
}

bool isEmpty(Element E){
	if((E.left==NULL) && (E.right==NULL)) return true;
	return false;
}

bool exist(Element E,int x){
	if(E->data==x){
		return true;
	}
else{
		while(E->right!=Null or E->left!=NULL){
			if(x>E->data){
				E->right=E->right;
			if(E->data==x){
				return true;
			}
			}
			else if (x<E->data){
				E->left=E->left;
			if(E->data==x){
				return true;
			}	
			}
		}
		return false
	}
}
 int count(Element E){
 
 	if(E->left==NULL && E->right==NULL){
 		return 0;
	 }
	 else{

       int number=1; 
        number += count(	E->left);  
        number += count(E->right); 
        return count;
	 }
 }

void main(){
	
}
