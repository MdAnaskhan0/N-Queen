#include<stdio.h>
#include<math.h>
int board[20],count=1;
int main(){
    int n,i,j;
    void queen(int row,int n);
    printf("\n\n Enter the number of Queen: ");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}

void result(int n){
    int i,j;
    printf("\n\n Solution %d: \n\n",count++);
    for(i=1; i<=n; i++){
        printf("\t%d",i);
    }
    for(i=1; i<=n; i++){
        printf("\n\n %d",i);
        for(j=1; j<=n; j++){
            if(board[i]==j){
                printf("\tQ");
            }
            else{
                printf("\t-");
            }
        }
    }
    printf("\n\n");
}


int place(int row, int col){
    int i;
    for(i=1; i<=row-1; i++){
        if(board[i]==col){
            return 0;
        }
        else{
            if(abs(board[i]-col)==abs(i-row)){
                return 0;
            }
        }
    }
    return 1;
}


void queen(int row, int n){
    int col;
    for(col=1; col<=n; col++){
        if(place(row,col)){
            board[row]=col;
            if(row == n){
                result(n);
            }
            else{
                queen(row+1,n);
            }
        }
    }
}
