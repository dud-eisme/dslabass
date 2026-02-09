#include<stdio.h>

#define MAX 5

int main(){

    int n;
    printf("Enter number of rows(including Header row) you want to enter :");
    scanf("%d",&n);

    int S_Matrix[n][3];
    int Matrix[MAX][MAX]={0};

    printf("Enter header row :\n");
    scanf("%d%d%d",&S_Matrix[0][0],&S_Matrix[0][1],&S_Matrix[0][2]);

    printf("Enter sparse matrix elements :\n");
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&S_Matrix[i][j]);
        }
        Matrix[S_Matrix[i][0]][S_Matrix[i][1]]=S_Matrix[i][2];
        printf("\n");
    }

    printf("Matrix :\n");
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }



    return 0;
}