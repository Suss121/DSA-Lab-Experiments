#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* insertAtBeginning(struct Node *head,int value){
    struct Node *newNode;
    struct Node *temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
    return head;
    
}
struct Node* insertAtEnd(struct Node* head, int value){
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
    newNode->next=head;
    return head;
}
struct Node* insertAtMid(struct Node* head,int value,int pos){
    if(pos==1){
        head=insertAtBeginning(head,60);
        return head;
    }
    struct Node *newNode;
    struct Node *temp=head;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    return head;

}
struct Node* deleteStart(struct Node* head){
    struct Node *temp=head;
    while(temp->next!=head){
        temp=temp->next;

    }
    temp->next=head->next;
    temp=head;
    head=temp->next;
    free(temp);
    return head;
}
struct Node* deleteEnd(struct Node* head){
    struct Node *temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    temp->next=head;
    temp=temp->next;
    free(temp);
    return head;

}
struct Node* deleteMid(struct Node* head,int pos){
    struct Node *temp=head;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp=temp->next;
    free(temp);
    return head;

}
void Traversal(struct Node* head){
    struct Node* temp;
    temp=head;
    do{
        printf(" %d-> ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
}
int main(){
    struct Node *head=NULL;
    int n,data;
    printf("Enter No. of elements you want in linked list ");
    scanf("%d",&n);
    printf("Enter %d values in linked list:",n);

    for(int i=0;i<n;i++){
        
        printf("\nvalue: ");
        scanf("%d",&data);
        head=insertAtEnd(head,data);
    }

    printf("Initially stored elements:\n");
    Traversal(head);

    head=insertAtMid(head,60,3);
    printf("\nAfter adding elements:\n");
    Traversal(head);

    head=deleteMid(head,2);
    printf("\nAfter deleting elements:\n");
    Traversal(head);

}