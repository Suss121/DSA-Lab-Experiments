#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* insertAtBeginning(struct Node *head,int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;  
    return head;
}
struct Node* insertAtEnd(struct Node *head,int value){
    struct Node *newNode;
    struct Node *temp;
    temp=head;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        return newNode;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
struct Node* insertAtMiddle(struct Node *head,int value,int pos){
    struct Node *newNode;
    struct Node *temp;
    int i;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(pos==1){
        newNode->next=head;
        return newNode;
    }
    temp=head;
    for(i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nInvalid Position");
        free(newNode);
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;

    return head;

}
void Traversal(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct Node* deleteStart(struct Node *head){
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    temp=head;
    head=temp->next;
    free(temp);
    return head;
}
struct Node* deleteLast(struct Node *head){
    struct Node *temp;
    struct Node *deleteNode;
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
     if (head->next == NULL) {
        free(head);
        return NULL;
    }
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    deleteNode = temp->next;
    temp->next = NULL;
    free(deleteNode);
    return head;

}
struct Node* deleteMid(struct Node *head,int pos){
    struct Node *temp;
    struct Node *deleteNode;
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (pos == 1) {
        deleteNode = head;
        head = head->next;
        free(deleteNode);
        return head;
    }
    temp=head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    deleteNode=temp->next;
    temp->next=deleteNode->next;
    free(deleteNode);
    return head;

}
int main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    head=(struct Node *)malloc(sizeof(struct Node));
    first=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=first;

    first->data=20;
    first->next=second;

    second->data=40;
    second->next=NULL;
    printf("Original List:\n");
    Traversal(head);
    head=insertAtMiddle(head,30,3);
    printf("After Adding element:\n");
    Traversal(head);

    head=deleteMid(head,2);
    printf("After Deleting element:\n");
    Traversal(head);
    return 0;
}