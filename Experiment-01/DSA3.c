#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node* insertAtBeginning(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    newNode->prev=NULL;
    head->prev=newNode;
    head=newNode;
    return head;
}
struct Node* insertAtEnd(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head == NULL)
    {
        head = newNode;
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
struct Node* insertAtMid(struct Node *head,int value,int pos){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    struct Node *temp=head;
    for(int i=1;i<pos-1 && temp->next!=NULL;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    temp=newNode->next;
    temp->prev=newNode;

    return head;
}
struct Node *deleteStart(struct Node *head){
    struct Node *temp=head;
    if(head==NULL){
        printf("Empty list");
        return head;
    }
    head=temp->next;
    head->prev=NULL;
    free(temp);
    return head;
}
struct Node *deleteEnd(struct Node *head){
    struct Node *temp=head;
    struct Node *deleteNode;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    deleteNode=temp->next;
    temp->next=NULL;
    free(deleteNode);
    return head;
}
struct Node *deleteMid(struct Node *head,int pos){
    struct Node *temp=head;
    struct Node *deleteNode;
    if(pos==1){
        head=deleteStart(head);
    }
    for(int i=1;i<pos-1 && temp->next!=NULL;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    deleteNode=temp->next;
    deleteNode->next->prev=temp;
    free(deleteNode);
    return head;

}
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf(" %d <->",temp->data);
        temp=temp->next;
    }
    printf(" NULL");
}
int main(){
    struct Node *head=NULL;
    int n,data;
    printf("Enter No. of elements you want in linked list");
    scanf("%d",&n);
    printf("Enter %d values in linked list",n);

    for(int i=0;i<n;i++){
        
        printf("\nvalue: ");
        scanf("%d",&data);
        head=insertAtEnd(head,data);
    }

    

    printf("Original linked list:\n");
    Traversal(head);

    printf("\nAfter adding elements\n");
    head=insertAtMid(head,50,3);
    Traversal(head);

    printf("\nAfter deleting elements\n");
    head=deleteMid(head,1);
    Traversal(head);
}