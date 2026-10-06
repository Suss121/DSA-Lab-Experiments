#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top=NULL;
void Push(int value){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
}
void Pop(){
    struct Node *temp;
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    temp=top;
    printf("Popped element:%d\n",top->data);
    top=top->next;
    free(temp);
}
void Peek(){
printf("\nTop Most element of stack is:%d\n",top->data);
}
void  Display(){
    struct Node *temp=top;
    if(temp==NULL){
        printf("Stack Underflow\n");
        return ;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    Push(10);
    Push(20);
    Push(30);
    printf("Elements of Stack are:\n");
    Display();
    Peek();
    Pop();
    printf("After deleting:\n");
    Display();
    return 0;
}