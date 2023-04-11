#include <stdio.h>
#include <stdlib.h>
int** createMatrix(int row, int column);
void PrintMatrix(int** matrix, int row, int column);
int** addition_Matrix(int** matrixA, int** matrixB, int row, int column);
int** subtraction_Matrix(int** matrixA, int** matrixB, int row, int column);
int** transpose_Matrix(int** matrix, int row, int column);
int** multiply_Matrix(int** matrixA, int Arow, int Acolumn, int** matrixB, int Brow, int Bcolumn);

int main() {
    printf("[----- [-----] [2022041046] -----]\n");
    int Arow = 0, Acolumn = 0, Brow = 0, Bcolumn = 0;
    int row=0, column=0;
    scanf("%d %d", &Arow, &Acolumn); // matrixA�� ��� ���� �Է¹���
    int** matrixA = createMatrix(Arow, Acolumn); //���� ������ matrixA�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < Arow; i++) { // matrixA��� �����
        for (int j = 0; j < Acolumn; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    scanf("%d %d", &Brow, &Bcolumn); // matrixB�� ��� ���� �Է¹���
    int** matrixB = createMatrix(Brow, Bcolumn); //���� ������ matrixA�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < Brow; i++) { // matrixB��� �����
        for (int j = 0; j < Bcolumn; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    if (Arow == Brow && Acolumn == Bcolumn) { //���� Arow�� Brow�� ���� Acolumn�� Bcolumn ������ ����
        int** matrixsum = addition_Matrix(matrixA, matrixB, row, column); //���� ������ matrixsum�� addition_Matrix�Լ� �ҷ�����
        printf("Matrix Sum:\n");
        PrintMatrix(matrixsum, row, column); //��� ���
    }
    else //�ƴ϶��
        printf("Matrix Sum:\n���� �Ұ���\n"); // <-�� ���� ���

    if (Arow == Brow && Acolumn == Bcolumn) {//���� Arow�� Brow�� ���� Acolumn�� Bcolumn ������ ����
        int** matrixsub = subtraction_Matrix(matrixA, matrixB, row, column); //���� ������ matrixsub�� subtraction_Matrix�Լ� �ҷ�����
        printf("Matrix Subtraction:\n");
        PrintMatrix(matrixsub, row, column); //��� ���
    }
    else //�ƴ϶��
        printf("Matrix Subtraction:\n���� �Ұ���\n"); // <-�� ���� ���

    row = Arow;       // row�� Arow�� �ޱ�
    column = Acolumn; // column�� Acolumn�� �ޱ�
    int** matrixtranspose = transpose_Matrix(matrixA, Arow, Acolumn); //���� ������ matrixtranspose�� transpose_Matrix�Լ� �ҷ�����
    printf("MatrixA Transpose:\n");
    PrintMatrix(matrixtranspose, column, row); //��� ���

    row = Brow;                                // row�� Brow�� �ޱ�
    column = Bcolumn;                          // column�� Bcolumn�� �ޱ�
    matrixtranspose = transpose_Matrix(matrixB, Brow, Bcolumn); //���� ������ matrixtranspose�� transpose_Matrix�Լ� �ҷ�����
    printf("MatrixB Transpose:\n");
    PrintMatrix(matrixtranspose, column, row); //��� ���

    if (Arow == Bcolumn && Brow == Acolumn) { //���� Arow�� Bcolumn�� ���� Brow�� Acolumn ������ ����
        int** matrixmultiply = multiply_Matrix(matrixA, Arow, Acolumn, matrixB, Brow, Bcolumn); //���� ������ matrixmultiply�� multiply_Matrix�Լ� �ҷ�����
        printf("Matrix Multiply:\n");
        PrintMatrix(matrixmultiply, row, column); //��� ���
    }
    else //�ƴ϶��
        printf("Matrix Multiply:\n���� �Ұ���\n"); // <-�� ���� ���

    return 0;
}

void PrintMatrix(int** matrix, int row, int column) { //��� ��� �Լ�
    for (int i = 0; i < row; i++) {                     // 0���� row-1����
        for (int j = 0; j < column; j++) {                // 0���� column-1����
            printf("%2d", matrix[i][j]);
        }
        printf("\n");
    }
}

int** createMatrix(int row, int column) {
    int** matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * column);
        for (int j = 0; j < column; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix; // matrix��ȯ
}

int** addition_Matrix(int** matrixA, int** matrixB, int row, int column) { // matrixA��İ� matrixB��� ���ϱ� �Լ� �����
    int** matrixsum = createMatrix(row, column); //���������� matrixsum�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < row; i++) {      // 0���� row-1����
        for (int j = 0; j < column; j++) { // 0���� column-1����
            matrixsum[i][j] = matrixA[i][j] + matrixB[i][j]; // ex>matrixsum[0][0]=matrixA[0][0]+matrixB[0][0], matrixsum[0][1]=matrixA[0][1]+matrixB[0][1]
        }
    }
    return matrixsum; // matrixsum ��ȯ
}

int** subtraction_Matrix(int** matrixA, int** matrixB, int row, int column) { // matrixA��İ� matrixB��� ���� �Լ� �����
    int** matrixsub = createMatrix(row, column); //���������� matrixsub�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < row; i++) {      // 0���� row-1����
        for (int j = 0; j < column; j++) { // 0���� column-1����
            matrixsub[i][j] = matrixA[i][j] - matrixB[i][j]; // ex>matrixsub[0][0]=matrixA[0][0]-matrixB[0][0],matrixsum[0][1]=matrixA[0][1]+matrixB[0][1]
        }
    }
    return matrixsub; // matrixsub ��ȯ
}

int** transpose_Matrix(int** matrix, int row, int column) { //��ġ��� �Լ� �����
    int** transpose = createMatrix(column, row); //���������� transpose�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < column; i++) { // 0���� row-1����
        for (int j = 0; j < row; j++) {  // 0���� column-1����
            transpose[i][j] = matrix[j][i]; // ex>transpose[0][0]=matrix[][0], transpose[0][1]=matrix[1][0],transpose[0][2]=matrix[2][0],...,transpose[1][0]=matrix[0][1]
        }
    }
    return transpose; // transpose ��ȯ
}

int** multiply_Matrix(int** matrixA, int Arow, int Acolumn, int** matrixB, int Brow, int Bcolumn) { // matrixA��İ� matrixB����� �� �Լ� �����
    int** result = createMatrix(Arow, Bcolumn); //���������� result�� createMatrix�Լ� �ҷ�����
    for (int i = 0; i < Arow; i++) {      // 0���� Arow-1����
        for (int j = 0; j < Bcolumn; j++) { // 0���� Bcolumn-1����
            result[i][j] = 0;
            for (int k = 0; k < Acolumn; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; //ex>result[0][0]= matrixA[0][0] * matrixB[0][0]+ matrixA[0][1] * matrixB[1][0], matrixA[0][2] * matrixB[2][0]
            }
        }
    }
    return result; // result ��ȯ
}