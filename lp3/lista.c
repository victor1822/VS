#include<stdio.h>
#include<stdlib.h>

struct Node{
int value;
struct Node *next;
};

void insertAfter(struct Node *root, int value){
root-> next = (struct Node*) malloc(sizeof(struct Node));
root->next->value=value;
root->next->next=NULL;
}

void insertBefore(struct Node **root,int value){

struct Node* n = (struct Node*)malloc(sizeof(struct Node));
n->value=value;
n->next=*root;
*root=n;

}

int main(){
struct Node *n1= (structNode*)malloc(sizeof(struct Node));
n1->value=10;
n1->next=NULL;
insertAfter(n1,20);
insertBefore(&n1,20)
}
