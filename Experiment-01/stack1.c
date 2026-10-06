#include <stdio.h>
#define SIZE 7
int main(){
    int stack[SIZE];
    int top=-1;
    printf("#########################\n 1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n#########################\n");
    int choice,value;
    char ch='y';
    
    while(ch=='y'){
        scanf("\n%d",&choice);
    switch (choice){
        case 1:
        if(top==SIZE-1){
            printf("Stack overflow");
        }
        else{
            printf("Enter no. to be added in stack : ");
            scanf("%d",&value);
            top++;
            stack[top]=value;
            printf("\nElement added successfully.\n");
        }
        break;

        case 2:
        if(top==-1){
            printf("Stack Underflow");
        }
        else{
            top--;
            printf("element removed successfully");
        }
        break;

        case 3:
        printf("Top most element of stack is %d\n",stack[top]);
        break;

        case 4:
        printf("All the elements of stack are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
        break;

        case 5:
        printf("EXIT");
        break;

    }
    printf("\nDo you wish to continue?");
    scanf(" %c",&ch);
    }
    
    return 0;
}