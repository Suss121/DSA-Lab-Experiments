#include<stdio.h>
#include<string.h>
void removeGroups(char board[],char result[]){
    int n=strlen(board);
    int j,c=0;
    for(int i=0;i<n;){
        
        for(int j=i;j<n && (board[i]==board[j]);j++){
        }
        if(j-i<3){
            for(int k=i;k<j;k++){
                result[c]=board[k];
                c++;
            }
        }
        i=j;
    }
    result[c]='\0';
    if(strlen(board)!=strlen(result)){
        char temp[100];
        removeGroups(result,temp);
        for(int i=0;i<strlen(temp);i++){
            result[i]=temp[i];
        }
    }
}
void insertBall(char board[],char ball,int pos,char newBoard[]){
    int n=strlen(board);
    int p=0;
    for(int i=0;i<pos;i++){
        newBoard[p]=board[i];
        p++;
    }
    newBoard[p]=ball;
    p++;
    for(int i=pos;i<n;i++){
        newBoard[p]=board[i];
        p++;
    }
    newBoard[p]='\0';
}
int solve(char board[],char hand[]){
    if(strlen(board)==0){
        return 0;
    }
    if(strlen(hand)==0){
        return -1;
    }
    int ans=-1;
    for(int h=0;h<strlen(hand);h++){
        char ball=hand[h];
        for(int pos=0;pos<=strlen(board);pos++){
            char newBoard[100];
            char afterRemove[100];
            char newHand[100];
            insertBall(board,ball,pos,newBoard);
            removeGroups(newBoard,afterRemove);
            int p=0;
            for(int i=0;i<strlen(hand);i++){
                if(i!=h){
                    newHand[p]=hand[i];
                    p++;
                }
            }
            newHand[p]='\0';
            int result=solve(afterRemove,newHand);
            if(result !=-1){
                result=result+1;
                if(ans==-1||result<ans){
                    ans=result;
            }
        }
            
        }
    }
    return ans;
}
int main(){
    char board[]="WWRRBBWW";
    char hand[]="WRBRW";

    printf("%d",solve(board,hand));

    return 0;
}