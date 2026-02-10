#include <stdio.h>

#define MAX 100

void readSparse(int sp[MAX][3]);
void displaySparse(int sp[MAX][3]);
void transposeSparse(int sp[MAX][3], int trans[MAX][3]);
void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]);
void multiplySparse(int a[MAX][3], int b[MAX][3], int prod[MAX][3]);

int main() {
    int A[MAX][3], B[MAX][3];
    int T[MAX][3], C[MAX][3];
    int choice;

    printf("Enter first sparse matrix:\n");
    readSparse(A);

    printf("\nEnter second sparse matrix:\n");
    readSparse(B);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Display Matrices\n");
        printf("2. Transpose Matrices\n");
        printf("3. Add Matrices\n");
        printf("4. Multiply Matrices\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nMatrix A:\n");
            displaySparse(A);
            printf("\nMatrix B:\n");
            displaySparse(B);
            break;

        case 2:
            printf("\nTranspose of Matrix A:\n");
            transposeSparse(A, T);
            displaySparse(T);

            printf("\nTranspose of Matrix B:\n");
            transposeSparse(B, T);
            displaySparse(T);
            break;

        case 3:
            if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
                printf("Addition not possible (dimension mismatch)\n");
            } else {
                addSparse(A, B, C);
                printf("\nSum Matrix:\n");
                displaySparse(C);
            }
            break;

        case 4:
            if (A[0][1] != B[0][0]) {
                printf("Multiplication not possible (dimension mismatch)\n");
            } else {
                multiplySparse(A, B, C);
                printf("\nProduct Matrix:\n");
                displaySparse(C);
            }
            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

void readSparse(int sp[MAX][3]) {
    int i;
    printf("Enter rows, columns, number of non-zero elements: ");
    scanf("%d %d %d", &sp[0][0], &sp[0][1], &sp[0][2]);

    for (i = 1; i <= sp[0][2]; i++) {
        printf("Enter row, column, value: ");
        scanf("%d %d %d", &sp[i][0], &sp[i][1], &sp[i][2]);
    }
}

void displaySparse(int sp[MAX][3]) {
    int i;
    printf("Row  Col  Val\n");
    for (i = 0; i <= sp[0][2]; i++) {
        printf("%3d  %3d  %3d\n", sp[i][0], sp[i][1], sp[i][2]);
    }
}

void transposeSparse(int sp[MAX][3], int trans[MAX][3]) {
    int i, j, k = 1;

    trans[0][0] = sp[0][1];
    trans[0][1] = sp[0][0];
    trans[0][2] = sp[0][2];

    for (i = 0; i < sp[0][1]; i++) {
        for (j = 1; j <= sp[0][2]; j++) {
            if (sp[j][1] == i) {
                trans[k][0] = sp[j][1];
                trans[k][1] = sp[j][0];
                trans[k][2] = sp[j][2];
                k++;
            }
        }
    }
}

void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    int i = 1, j = 1, k = 1;

    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] ||
                  (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        } else {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        }
    }

    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

void multiplySparse(int a[MAX][3], int b[MAX][3], int prod[MAX][3]) {
    int i, j, k = 1;

    prod[0][0] = a[0][0];
    prod[0][1] = b[0][1];

    for (i = 1; i <= a[0][2]; i++) {
        for (j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                prod[k][0] = a[i][0];
                prod[k][1] = b[j][1];
                prod[k][2] = a[i][2] * b[j][2];
                k++;
            }
        }
    }
    prod[0][2] = k - 1;
}
