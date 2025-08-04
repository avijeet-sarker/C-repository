#include <stdio.h>

#define MAX 100

void displayTuple(int tuple[MAX][3], int size) {
    printf("\nRow\tCol\tVal\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int addTuples(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Addition not possible. Matrices dimensions do not match.\n");
        return 0;
    }

    int i = 1, j = 1, k = 1;
    result[0][0] = A[0][0];
    result[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++; k++;
        } else {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i <= A[0][2]) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
    return k;
}

int main() {
    int A[MAX][3], B[MAX][3], sum[MAX][3];
    int aSize, bSize;

    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &aSize);
    printf("Enter the 3-tuple for Matrix A (row col val):\n");
    for (int i = 0; i < aSize; i++)
        scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);

    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &bSize);
    printf("Enter the 3-tuple for Matrix B (row col val):\n");
    for (int i = 0; i < bSize; i++)
        scanf("%d%d%d", &B[i][0], &B[i][1], &B[i][2]);

    int resultSize = addTuples(A, B, sum);

    printf("\nResultant Matrix in 3-Tuple Format:\n");
    displayTuple(sum, resultSize);

    return 0;
}
