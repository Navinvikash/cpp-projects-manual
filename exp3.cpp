#include <iostream>
using namespace std;

class Matrix
{
public:
    int a[2][2];

    Matrix()
    {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }

    Matrix operator+(Matrix b)
    {
        Matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                c.a[i][j] = a[i][j] + b.a[i][j];
        return c;
    }

    Matrix operator*(Matrix b)
    {
        Matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    c.a[i][j] += a[i][k] * b.a[k][j];
        return c;
    }

    void show()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Matrix A, B;
    A.a[0][0] = 1; A.a[0][1] = 2; A.a[1][0] = 3; A.a[1][1] = 4;
    B.a[0][0] = 5; B.a[0][1] = 6; B.a[1][0] = 7; B.a[1][1] = 8;

    Matrix sum = A + B;
    Matrix product = A * B;

    cout << "Matrix A:" << endl;
    A.show();
    cout << "Matrix B:" << endl;
    B.show();
    cout << "Addition of Matrices:" << endl;
    sum.show();
    cout << "Multiplication of Matrices:" << endl;
    product.show();
    return 0;
}