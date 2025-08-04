#include <stdio.h>

int countNonZero(int matrix[][10], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
    }
    return count;
}

int main() {
    int matrix[10][10];
    int n;

    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonZeroCount = countNonZero(matrix, n);
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    return 0;
}
