#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;
Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix sub(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
Matrix naiveMultiply(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
Matrix strassenMultiply(Matrix A, Matrix B) {
    int n = A.size();
    if (n == 1)
        return {{A[0][0] * B[0][0]}};
    int half = n / 2;
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    Matrix M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenMultiply(add(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, sub(B12, B22));
    Matrix M4 = strassenMultiply(A22, sub(B21, B11));
    Matrix M5 = strassenMultiply(add(A11, A12), B22);
    Matrix M6 = strassenMultiply(sub(A21, A11), add(B11, B12));
    Matrix M7 = strassenMultiply(sub(A12, A22), add(B21, B22));
    Matrix C11 = add(sub(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(sub(add(M1, M3), M2), M6);
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
    return C;
}
void printMatrix(Matrix A) {
    for (auto &row : A) {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }
}
bool compareMatrices(Matrix A, Matrix B) {
    return A == B;
}
int main() {
    // 2x2 Test Case
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    cout << "2x2 Strassen Result:\n";
    printMatrix(strassenMultiply(A2, B2));
    cout << "2x2 Naive Result:\n";
    printMatrix(naiveMultiply(A2, B2));
    cout << "Match: " << (compareMatrices(strassenMultiply(A2, B2), naiveMultiply(A2, B2)) ? "Yes" : "No") << "\n\n";
    // 4x4 Test Case
    Matrix A4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix B4 = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    cout << "4x4 Strassen Result:\n";
    printMatrix(strassenMultiply(A4, B4));
    cout << "4x4 Naive Result:\n";
    printMatrix(naiveMultiply(A4, B4));
    cout << "Match: " << (compareMatrices(strassenMultiply(A4, B4), naiveMultiply(A4, B4)) ? "Yes" : "No") << "\n\n";
    // Random Test Case (8x8)
    srand(time(0));
    int n = 8;
    Matrix Ar(n, vector<int>(n)), Br(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            Ar[i][j] = rand() % 10;
            Br[i][j] = rand() % 10;
        }
    Matrix strassenResult = strassenMultiply(Ar, Br);
    Matrix naiveResult = naiveMultiply(Ar, Br);
    cout << "Random 8x8 Test - Match: " << (compareMatrices(strassenResult, naiveResult) ? "Yes" : "No") << "\n";
    return 0;
}