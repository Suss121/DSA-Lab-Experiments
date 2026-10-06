#include<stdio.h>
#include<stdlib.h>
//Reversal of singly LL
struct Node{
    int data;
    struct Node *next;
};
struct Node *Reversal(struct Node *head){
    struct Node *prev=NULL;
    struct Node *current=head;
    struct Node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    print("NULL");
}
struct Node *insertAtEnd(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        return newNode;
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    return head;
}
int main(){
    struct Node *head=NULL;
    int n,value;
    printf("Enter No. of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=insertAtEnd(head,value);
    }
    head=Reversal(head);
    Traversal(head);
}