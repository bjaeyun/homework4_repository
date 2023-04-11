#include <stdio.h>
#include <stdlib.h>
int** createMatrix(int row, int column);
void PrintMatrix(int** matrix, int row, int column);
int** addition_Matrix(int** matrixA, int** matrixB, int row, int column);
int** subtraction_Matrix(int** matrixA, int** matrixB, int row, int column);
int** transpose_Matrix(int** matrix, int row, int column);
int** multiply_Matrix(int** matrixA, int Arow, int Acolumn, int** matrixB, int Brow, int Bcolumn);

int main() {
    printf("[----- [변재윤] [2022041046] -----]\n");
    int Arow = 0, Acolumn = 0, Brow = 0, Bcolumn = 0;
    int row=0, column=0;
    scanf("%d %d", &Arow, &Acolumn); // matrixA의 행과 열을 입력받음
    int** matrixA = createMatrix(Arow, Acolumn); //이중 포인터 matrixA에 createMatrix함수 불러오기
    for (int i = 0; i < Arow; i++) { // matrixA행렬 만들기
        for (int j = 0; j < Acolumn; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    scanf("%d %d", &Brow, &Bcolumn); // matrixB의 행과 열을 입력받음
    int** matrixB = createMatrix(Brow, Bcolumn); //이중 포인터 matrixA에 createMatrix함수 불러오기
    for (int i = 0; i < Brow; i++) { // matrixB행렬 만들기
        for (int j = 0; j < Bcolumn; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    if (Arow == Brow && Acolumn == Bcolumn) { //만약 Arow와 Brow가 같고 Acolumn와 Bcolumn 같으면 실행
        int** matrixsum = addition_Matrix(matrixA, matrixB, row, column); //이중 포인터 matrixsum에 addition_Matrix함수 불러오기
        printf("Matrix Sum:\n");
        PrintMatrix(matrixsum, row, column); //행렬 출력
    }
    else //아니라면
        printf("Matrix Sum:\n구현 불가능\n"); // <-이 문장 출력

    if (Arow == Brow && Acolumn == Bcolumn) {//만약 Arow와 Brow가 같고 Acolumn와 Bcolumn 같으면 실행
        int** matrixsub = subtraction_Matrix(matrixA, matrixB, row, column); //이중 포인터 matrixsub에 subtraction_Matrix함수 불러오기
        printf("Matrix Subtraction:\n");
        PrintMatrix(matrixsub, row, column); //행렬 출력
    }
    else //아니라면
        printf("Matrix Subtraction:\n구현 불가능\n"); // <-이 문장 출력

    row = Arow;       // row에 Arow값 받기
    column = Acolumn; // column에 Acolumn값 받기
    int** matrixtranspose = transpose_Matrix(matrixA, Arow, Acolumn); //이중 포인터 matrixtranspose에 transpose_Matrix함수 불러오기
    printf("MatrixA Transpose:\n");
    PrintMatrix(matrixtranspose, column, row); //행렬 출력

    row = Brow;                                // row에 Brow값 받기
    column = Bcolumn;                          // column에 Bcolumn값 받기
    matrixtranspose = transpose_Matrix(matrixB, Brow, Bcolumn); //이중 포인터 matrixtranspose에 transpose_Matrix함수 불러오기
    printf("MatrixB Transpose:\n");
    PrintMatrix(matrixtranspose, column, row); //행렬 출력

    if (Arow == Bcolumn && Brow == Acolumn) { //만약 Arow와 Bcolumn가 같고 Brow와 Acolumn 같으면 실행
        int** matrixmultiply = multiply_Matrix(matrixA, Arow, Acolumn, matrixB, Brow, Bcolumn); //이중 포인터 matrixmultiply에 multiply_Matrix함수 불러오기
        printf("Matrix Multiply:\n");
        PrintMatrix(matrixmultiply, row, column); //행렬 출력
    }
    else //아니라면
        printf("Matrix Multiply:\n구현 불가능\n"); // <-이 문장 출력

    return 0;
}

void PrintMatrix(int** matrix, int row, int column) { //행렬 출력 함수
    for (int i = 0; i < row; i++) {                     // 0부터 row-1까지
        for (int j = 0; j < column; j++) {                // 0부터 column-1까지
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
    return matrix; // matrix반환
}

int** addition_Matrix(int** matrixA, int** matrixB, int row, int column) { // matrixA행렬과 matrixB행렬 더하기 함수 만들기
    int** matrixsum = createMatrix(row, column); //이중포인터 matrixsum에 createMatrix함수 불러오기
    for (int i = 0; i < row; i++) {      // 0부터 row-1까지
        for (int j = 0; j < column; j++) { // 0부터 column-1까지
            matrixsum[i][j] = matrixA[i][j] + matrixB[i][j]; // ex>matrixsum[0][0]=matrixA[0][0]+matrixB[0][0], matrixsum[0][1]=matrixA[0][1]+matrixB[0][1]
        }
    }
    return matrixsum; // matrixsum 반환
}

int** subtraction_Matrix(int** matrixA, int** matrixB, int row, int column) { // matrixA행렬과 matrixB행렬 빼기 함수 만들기
    int** matrixsub = createMatrix(row, column); //이중포인터 matrixsub에 createMatrix함수 불러오기
    for (int i = 0; i < row; i++) {      // 0부터 row-1까지
        for (int j = 0; j < column; j++) { // 0부터 column-1까지
            matrixsub[i][j] = matrixA[i][j] - matrixB[i][j]; // ex>matrixsub[0][0]=matrixA[0][0]-matrixB[0][0],matrixsum[0][1]=matrixA[0][1]+matrixB[0][1]
        }
    }
    return matrixsub; // matrixsub 반환
}

int** transpose_Matrix(int** matrix, int row, int column) { //전치행렬 함수 만들기
    int** transpose = createMatrix(column, row); //이중포인터 transpose에 createMatrix함수 불러오기
    for (int i = 0; i < column; i++) { // 0부터 row-1까지
        for (int j = 0; j < row; j++) {  // 0부터 column-1까지
            transpose[i][j] = matrix[j][i]; // ex>transpose[0][0]=matrix[][0], transpose[0][1]=matrix[1][0],transpose[0][2]=matrix[2][0],...,transpose[1][0]=matrix[0][1]
        }
    }
    return transpose; // transpose 반환
}

int** multiply_Matrix(int** matrixA, int Arow, int Acolumn, int** matrixB, int Brow, int Bcolumn) { // matrixA행렬과 matrixB행렬의 곱 함수 만들기
    int** result = createMatrix(Arow, Bcolumn); //이중포인터 result에 createMatrix함수 불러오기
    for (int i = 0; i < Arow; i++) {      // 0부터 Arow-1까지
        for (int j = 0; j < Bcolumn; j++) { // 0부터 Bcolumn-1까지
            result[i][j] = 0;
            for (int k = 0; k < Acolumn; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; //ex>result[0][0]= matrixA[0][0] * matrixB[0][0]+ matrixA[0][1] * matrixB[1][0], matrixA[0][2] * matrixB[2][0]
            }
        }
    }
    return result; // result 반환
}