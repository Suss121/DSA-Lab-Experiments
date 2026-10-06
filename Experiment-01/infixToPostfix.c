#include<stdio.h>
#define N 13
static int top=-1;
char s[N];
void push(char a,char s[]){
    top++;
    s[top]=a;
}
char pop(char s[]){
    char j;
    if(top>=0){
        j=s[top];
        top--;
    }
    return j;
}
int precedence(char a){
    if(a=='+'||a=='-'){
        return 1;
    }
    else if(a=='*'||a=='/'||a=='%'){
        return 2;
    }
    else return 3;

    return 0;
}
void postfix(char a[],char s[]){
    char expr[N];
    int p=0;
    for(int i=0;i<N;i++){
        if(a[i]>='A' && a[i]<='Z'){
            expr[p]=a[i];
            p++;
        }
        else if(a[i]=='('){
            push(a[i],s);
        }
        else if(a[i]==')'){
            while(top>=0 && s[top]!='('){
                char val=pop(s);
                expr[p]=val;
                p++;
            }
            if(top>=0){
                pop(s);
            }
        }
        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%'||a[i]=='^'){
            while(top>=0 && s[top]!='('&&(precedence(s[top])>precedence(a[i])||precedence(s[top])==precedence(a[i])||a[i]=='^')){
               char val=pop(s);
               expr[p]=val;
               p++; 
            }
            push(a[i],s);
        }
    }
    while(top>=0){
        char val=pop(s);
        expr[p]=val;
        p++; 

    }
    for(int i=0;i<N;i++){
        printf("%c",expr[i]);
    }
}
int main(){
    char a[N]="(X^Y/(A*Z)+B)";
    
    postfix(a,s);
}