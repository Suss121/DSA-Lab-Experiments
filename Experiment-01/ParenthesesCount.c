#include<stdio.h>
static int cn=0;
int g=0;
void push(char a,char s[]){
    s[cn]=a;
    cn++;
    g++;
}
void pop(char s[]){
    if(s!=NULL)
    cn--;
}
int count_parentheses(char a[],int n,char s[]){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]=='(' && i!=n-1){
            push(a[i],s);
        }
        else if(cn>0 && a[i]==')'){
            pop(s);
            c+=2;
        }
        else{
            printf("%c\n",a[i]);
        }
    }
    return c;
}

int main(){
    char a[10]={'(','(','(',')',')',')','(',')',')','('};
    char s[10];
    int b=count_parentheses(a,10,s);
    printf("%d\n",b);
    printf("growth of stack is %d",g);
}