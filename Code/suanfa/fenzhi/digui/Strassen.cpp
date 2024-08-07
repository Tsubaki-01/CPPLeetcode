#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

template <typename T>
void ShowMatrix(T **Matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

template <typename T>
class Strassen
{
public:
    void ADD(T **MatrixA, T **MatrixB, T **MatrixResult, int size);
    void SUB(T **MatrixA, T **MatrixB, T **MatrixResult, int size);
    void NormalMul(T **MatrixA, T **MatrixB, T **MatrixResult, int size);
    void StrassenMul(T **MatrixA, T **MatrixB, T **MatrixResult, int size);
    void FillMatrix(T **MatrixA, T **MatrixB, int size); // 给A、B矩阵赋初值
    // void ShowMatrix(T **Matrix, int size);
    int GetMatrixSum(T **Matrix, int size);
    // 用来计算矩阵各个元素的和，如果两种算法得出的矩阵的和相等则认为算法正确。
};

template <typename T>
void Strassen<T>::ADD(T **MatrixA, T **MatrixB, T **MatrixResult, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MatrixResult[i][j] = MatrixA[i][j] + MatrixB[i][j];
        }
    }
}

template <typename T>
void Strassen<T>::SUB(T **MatrixA, T **MatrixB, T **MatrixResult, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MatrixResult[i][j] = MatrixA[i][j] - MatrixB[i][j];
        }
    }
}

template <typename T>
void Strassen<T>::NormalMul(T **MatrixA, T **MatrixB, T **MatrixResult, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MatrixResult[i][j] = 0;
            for (int k = 0; k < size; k++)
                MatrixResult[i][j] += MatrixA[i][k] * MatrixB[k][j];
        }
    }
}

template <typename T>
void Strassen<T>::FillMatrix(T **MatrixA, T **MatrixB, int size) // 给A、B矩阵赋初值
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MatrixA[i][j] = MatrixB[i][j] = 1;
        }
    }
}

template <typename T>
void Strassen<T>::StrassenMul(T **MatrixA, T **MatrixB, T **MatrixResult, int size)
{
    // if ( size <= 64 )
    // 分治门槛，小于这个值时不再进行递归计算，而是采用常规矩阵计算方法
    // {
    // 	NormalMul(MatrixA, MatrixB, MatrixResult, size);
    // }
    if (size == 1)
    {
        MatrixResult[0][0] = MatrixA[0][0] * MatrixB[0][0];
    }
    else
    {
        int half_size = size / 2;
        T **A11;
        T **A12;
        T **A21;
        T **A22;
        T **B11;
        T **B12;
        T **B21;
        T **B22;
        T **C11;
        T **C12;
        T **C21;
        T **C22;
        T **M1;
        T **M2;
        T **M3;
        T **M4;
        T **M5;
        T **M6;
        T **M7;
        T **MatrixTemp1;
        T **MatrixTemp2;

        A11 = new int *[half_size];
        A12 = new int *[half_size];
        A21 = new int *[half_size];
        A22 = new int *[half_size];

        B11 = new int *[half_size];
        B12 = new int *[half_size];
        B21 = new int *[half_size];
        B22 = new int *[half_size];

        C11 = new int *[half_size];
        C12 = new int *[half_size];
        C21 = new int *[half_size];
        C22 = new int *[half_size];

        M1 = new int *[half_size];
        M2 = new int *[half_size];
        M3 = new int *[half_size];
        M4 = new int *[half_size];
        M5 = new int *[half_size];
        M6 = new int *[half_size];
        M7 = new int *[half_size];
        MatrixTemp1 = new int *[half_size];
        MatrixTemp2 = new int *[half_size];

        for (int i = 0; i < half_size; i++)
        {
            A11[i] = new int[half_size];
            A12[i] = new int[half_size];
            A21[i] = new int[half_size];
            A22[i] = new int[half_size];

            B11[i] = new int[half_size];
            B12[i] = new int[half_size];
            B21[i] = new int[half_size];
            B22[i] = new int[half_size];

            C11[i] = new int[half_size];
            C12[i] = new int[half_size];
            C21[i] = new int[half_size];
            C22[i] = new int[half_size];

            M1[i] = new int[half_size];
            M2[i] = new int[half_size];
            M3[i] = new int[half_size];
            M4[i] = new int[half_size];
            M5[i] = new int[half_size];
            M6[i] = new int[half_size];
            M7[i] = new int[half_size];

            MatrixTemp1[i] = new int[half_size];
            MatrixTemp2[i] = new int[half_size];
        }

        // 赋值
        for (int i = 0; i < half_size; i++)
        {
            for (int j = 0; j < half_size; j++)
            {
                A11[i][j] = MatrixA[i][j];
                A12[i][j] = MatrixA[i][j + half_size];
                A21[i][j] = MatrixA[i + half_size][j];
                A22[i][j] = MatrixA[i + half_size][j + half_size];

                B11[i][j] = MatrixB[i][j];
                B12[i][j] = MatrixB[i][j + half_size];
                B21[i][j] = MatrixB[i + half_size][j];
                B22[i][j] = MatrixB[i + half_size][j + half_size];
            }
        }

        // calculate M1
        ADD(A11, A22, MatrixTemp1, half_size);
        ADD(B11, B22, MatrixTemp2, half_size);
        StrassenMul(MatrixTemp1, MatrixTemp2, M1, half_size);

        // calculate M2
        ADD(A21, A22, MatrixTemp1, half_size);
        StrassenMul(MatrixTemp1, B11, M2, half_size);

        // calculate M3
        SUB(B12, B22, MatrixTemp1, half_size);
        StrassenMul(A11, MatrixTemp1, M3, half_size);

        // calculate M4
        SUB(B21, B11, MatrixTemp1, half_size);
        StrassenMul(A22, MatrixTemp1, M4, half_size);

        // calculate M5
        ADD(A11, A12, MatrixTemp1, half_size);
        StrassenMul(MatrixTemp1, B22, M5, half_size);

        // calculate M6
        SUB(A21, A11, MatrixTemp1, half_size);
        ADD(B11, B12, MatrixTemp2, half_size);
        StrassenMul(MatrixTemp1, MatrixTemp2, M6, half_size);

        // calculate M7
        SUB(A12, A22, MatrixTemp1, half_size);
        ADD(B21, B22, MatrixTemp2, half_size);
        StrassenMul(MatrixTemp1, MatrixTemp2, M7, half_size);

        // show M1-M7
        if (size == 16)
        {
            cout << "M1:" << endl;
            ShowMatrix(M1, 8);
            cout << "M2:" << endl;
            ShowMatrix(M2, 8);
            cout << "M3:" << endl;
            ShowMatrix(M3, 8);
            cout << "M4:" << endl;
            ShowMatrix(M4, 8);
            cout << "M5:" << endl;
            ShowMatrix(M5, 8);
            cout << "M6:" << endl;
            ShowMatrix(M6, 8);
            cout << "M7:" << endl;
            ShowMatrix(M7, 8);
        }

        // C11
        ADD(M1, M4, C11, half_size);
        SUB(C11, M5, C11, half_size);
        ADD(C11, M7, C11, half_size);

        // C12
        ADD(M3, M5, C12, half_size);

        // C21
        ADD(M2, M4, C21, half_size);

        // C22
        SUB(M1, M2, C22, half_size);
        ADD(C22, M3, C22, half_size);
        ADD(C22, M6, C22, half_size);

        // 赋值
        for (int i = 0; i < half_size; i++)
        {
            for (int j = 0; j < half_size; j++)
            {
                MatrixResult[i][j] = C11[i][j];
                MatrixResult[i][j + half_size] = C12[i][j];
                MatrixResult[i + half_size][j] = C21[i][j];
                MatrixResult[i + half_size][j + half_size] = C22[i][j];
            }
        }

        // 释放申请的内存
        for (int i = 0; i < half_size; i++)
        {
            delete[] A11[i];
            delete[] A12[i];
            delete[] A21[i];
            delete[] A22[i];

            delete[] B11[i];
            delete[] B12[i];
            delete[] B21[i];
            delete[] B22[i];

            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];

            delete[] M1[i];
            delete[] M2[i];
            delete[] M3[i];
            delete[] M4[i];
            delete[] M5[i];
            delete[] M6[i];
            delete[] M7[i];

            delete[] MatrixTemp1[i];
            delete[] MatrixTemp2[i];
        }
        delete[] A11;
        delete[] A12;
        delete[] A21;
        delete[] A22;

        delete[] B11;
        delete[] B12;
        delete[] B21;
        delete[] B22;

        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;

        delete[] M1;
        delete[] M2;
        delete[] M3;
        delete[] M4;
        delete[] M5;
        delete[] M6;
        delete[] M7;

        delete[] MatrixTemp1;
        delete[] MatrixTemp2;
    }
}

template <typename T>
int Strassen<T>::GetMatrixSum(T **Matrix, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += Matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    long startTime_normal, endTime_normal;
    long startTime_strasse, endTime_strassen;

    // srand(time(0));

    Strassen<int> stra;
    int N;
    cout << "please input the size of Matrix,and the size must be the power of 2:" << endl;
    cin >> N;

    int **Matrix1 = new int *[N];
    int **Matrix2 = new int *[N];
    int **Matrix3 = new int *[N];
    for (int i = 0; i < N; i++)
    {
        Matrix1[i] = new int[N];
        Matrix2[i] = new int[N];
        Matrix3[i] = new int[N];
    }

    stra.FillMatrix(Matrix1, Matrix2, N);

    cout << "Strassen算法" << endl;
    // cout << "Strassen算法开始时间：" << (startTime_strasse = clock()) << endl;
    stra.StrassenMul(Matrix1, Matrix2, Matrix3, N);
    // cout << "Strassen算法结束时间：" << (endTime_strassen = clock()) << endl;
    // cout << "总时间:" << endTime_strassen - startTime_strasse << endl;
    cout << "sum = " << stra.GetMatrixSum(Matrix3, N) << ';' << endl
         << "Final Matrix" << endl;
    ShowMatrix(Matrix3, N);
    cout << endl;

    cout << "朴素算法" << endl;
    // cout << "朴素算法开始时间：" << (startTime_normal = clock()) << endl;
    stra.NormalMul(Matrix1, Matrix2, Matrix3, N);
    // cout << "朴素算法结束时间：" << (endTime_normal = clock()) << endl;
    // cout << "总时间:" << endTime_normal - startTime_normal << endl;
    cout << "sum = " << stra.GetMatrixSum(Matrix3, N) << ';' << endl;
}
