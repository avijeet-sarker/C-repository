 #include <stdio.h>

#define MAX 100

void readSparseMatrix(int mat[MAX][MAX], int *rows, int *cols) {
    printf("Enter number of rows and columns: ");
    scanf("%d%d", rows, cols);

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int convertToTuple(int mat[MAX][MAX], int rows, int cols, int tuple[MAX][3]) {
    int k = 1; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = mat[i][j];
                k++;
            }
        }
    }
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = k - 1; 
    return k;
}

void transposeTuple(int tuple[MAX][3], int trans[MAX][3]) {
    int n = tuple[0][2]; 
    trans[0][0] = tuple[0][1]; 
    trans[0][1] = tuple[0][0]; 
    trans[0][2] = n;

    int k = 1;
    for (int col = 0; col < tuple[0][1]; col++) {
        for (int i = 1; i <= n; i++) {
            if (tuple[i][1] == col) {
                trans[k][0] = tuple[i][1];
                trans[k][1] = tuple[i][0];
                trans[k][2] = tuple[i][2];
                k++;
            }
        }
    }
}

void displayTuple(int tuple[MAX][3], int count) {
    printf("\nRow\tCol\tVal\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int mat[MAX][MAX], tuple[MAX][3], trans[MAX][3];
    int rows, cols;

    readSparseMatrix(mat, &rows, &cols);

    int count = convertToTuple(mat, rows, cols, tuple);

    printf("\n3-Tuple representation of original matrix:\n");
    displayTuple(tuple, count);

    transposeTuple(tuple, trans);

    printf("\n3-Tuple representation of transposed matrix:\n");
    displayTuple(trans, count);

    return 0;
}

