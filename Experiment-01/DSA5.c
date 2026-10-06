#include<stdio.h>
#include<stdlib.h>
//Reversal of circular doubly LL
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
 struct Node *insertAtEnd(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if (head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=head;
    head->prev=newNode;
    return head;
 }
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp->next!=head){
        printf(" %d<->",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);
}
struct Node* Reversal(struct Node *head){
    if(head==NULL || head->next==head){
        return 0;
    }
    struct Node* temp=head;
    struct Node *nextNode;
    do{
        nextNode=temp->next;
        temp->next=temp->prev;
        temp->prev=nextNode;
        temp=nextNode;
        }
    while(temp!=head);
    head=head->next;
    return head;
}
int main(){
    struct Node *head=NULL;
    printf("Enter no. of elements you wan to insert:\n");
    int n, value;
    scanf("%d",&n);
    printf("Enter data of linked list :\n ");
    for(int i=0;i<n;i++){
        scanf("%d",&value); 
        head=insertAtEnd(head,value);
    }
    head=Reversal(head);
    Traversal(head);
    return 0;
}