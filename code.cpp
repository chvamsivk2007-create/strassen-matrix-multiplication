#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Mat;

Mat add(Mat &A, Mat &B) {
    int n = A.size();
    Mat C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Mat sub(Mat &A, Mat &B) {
    int n = A.size();
    Mat C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Mat strassen(Mat &A, Mat &B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};

    int m = n / 2;
    Mat A11(m, vector<int>(m)), A12(m, vector<int>(m)), A21(m, vector<int>(m)), A22(m, vector<int>(m));
    Mat B11(m, vector<int>(m)), B12(m, vector<int>(m)), B21(m, vector<int>(m)), B22(m, vector<int>(m));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];       A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];   A22[i][j] = A[i + m][j + m];
            B11[i][j] = B[i][j];       B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];   B22[i][j] = B[i + m][j + m];
        }

    Mat S1 = add(A11, A22), S2 = add(B11, B22);
    Mat S3 = add(A21, A22);
    Mat S4 = sub(B12, B22);
    Mat S5 = sub(B21, B11);
    Mat S6 = add(A11, A12);
    Mat S7 = sub(A21, A11), S8 = add(B11, B12);
    Mat S9 = sub(A12, A22), S10 = add(B21, B22);

    Mat M1 = strassen(S1, S2);
    Mat M2 = strassen(S3, B11);
    Mat M3 = strassen(A11, S4);
    Mat M4 = strassen(A22, S5);
    Mat M5 = strassen(S6, B22);
    Mat M6 = strassen(S7, S8);
    Mat M7 = strassen(S9, S10);

    Mat T1 = add(M1, M4), T2 = sub(T1, M5);
    Mat C11 = add(T2, M7);
    Mat C12 = add(M3, M5);
    Mat C21 = add(M2, M4);
    Mat T3 = add(M1, M3), T4 = sub(T3, M2);
    Mat C22 = add(T4, M6);

    Mat C(n, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    return C;
}

int main() {
    int n;
    cout << "Enter size (power of 2): ";
    cin >> n;

    Mat A(n, vector<int>(n)), B(n, vector<int>(n));
    cout << "Enter matrix A:\n";
    for (auto &row : A) for (auto &x : row) cin >> x;
    cout << "Enter matrix B:\n";
    for (auto &row : B) for (auto &x : row) cin >> x;

    Mat C = strassen(A, B);

    cout << "Result:\n";
    for (auto &row : C) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
