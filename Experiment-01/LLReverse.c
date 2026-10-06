#include<stdio.h>
#include<stdlib.h>
//Reversal of circular LL
struct Node{
    int data;
    struct Node *next;
};
struct Node *insertAtEnd(struct Node* head,int value){
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return head;
}
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp->next!=head){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);

}   
struct Node *Reversal(struct Node *head){
    struct Node *prev=head;
    struct Node *current=head->next;
    struct Node *next;
    do{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    while(current!=head);
        head->next=prev;
        head=prev;
        return head;
    
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