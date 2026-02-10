#include<stdio.h>

int main(){

    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    int matrix[r][c],count=0;
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j]!=0)
                count++;
        }
    }

    printf("Non-zero elements : %d\n",count);
    printf("zero elements : %d\n",r*c-count);
    (r*c-count > count) ? printf("Sparse Matrix\n") : printf("Not a Sparse Matrix\n");
    return 0;
}