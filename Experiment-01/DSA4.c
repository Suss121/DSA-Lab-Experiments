#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;   
};
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp->next!=head){
        printf(" %d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
struct Node* insertAtBeginning(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    struct Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    head->prev=newNode;
    newNode->prev=temp;
    newNode->next=head;
    head=newNode;
    return head;
}
struct Node* insertAtEnd(struct Node *head,int value){
    struct Node *newNode;
    struct Node *temp=head;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    head->prev=newNode;
    newNode->next=head;
    return head;
}
struct Node *insertAtMid(struct Node *head,int value,int pos){
    struct Node *temp=head;
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next=newNode;
    temp=newNode->next;
    temp->prev=newNode;
    return head;
}
struct Node* deleteStart(struct Node *head){
    struct Node* temp=head;
    struct Node *deleteNode=head;
    if(head==NULL){
        printf("Empty List");
        return head;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    head->prev=temp;
    free(deleteNode);
    return head;

}
struct Node* deleteEnd(struct Node *head){
    struct Node *temp=head;
    struct Node *deleteNode;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    deleteNode=temp->next;
    temp->next=head;
    head->prev=temp;
    free(deleteNode);
    return head;
    
}
struct Node *deleteMid(struct Node *head,int pos){
    struct Node *temp=head;
    struct Node *deleteNode;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    deleteNode=temp->next;
    temp->next=deleteNode->next;
    temp=deleteNode->next;
    temp->prev=deleteNode->prev;
    free(deleteNode);
    return head;
}

int main(){
    int n,value;
    struct Node *head=NULL;
    printf("No. of elements you want in linked list:");
    scanf("%d",&n);
    printf("Enter %d values: \n",n);

    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=insertAtEnd(head,value);
    }

    printf("Original Linked List:\n");
    Traversal(head);

    printf("\nAfter deleting elements:\n");
    head=deleteMid(head,3);
    Traversal(head);
}


