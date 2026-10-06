#include<stdio.h>
#include<stdlib.h>
//Reversal of doubly LL
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node* insertAtEnd(struct Node *head,int value){
    struct Node* newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=NULL;
    return head;
}
void Traversal(struct Node *head){
    struct Node * temp=head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }
}
struct Node *Reversal(struct Node *head){
   struct Node *prev=NULL;
   struct Node *current=head;
   struct Node *next=NULL;
   while(current!=NULL){
    next=current->next;
    current->next=prev;
    current->prev=next;
    prev=current;
    current=next;
   }
   return prev;
}
int main(){
    int value;
    struct Node *head=NULL;
    for(int i=0;i<4;i++){
        scanf("%d",&value);
        head=insertAtEnd(head,value);
    }
    head=Reversal(head);
    Traversal(head);
}