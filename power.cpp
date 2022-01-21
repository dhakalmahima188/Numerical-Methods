#include <iostream>
using namespace std;
#include <math.h>
#define size 10
int main()
{
    float a[size][size], x[size], temp, ans, e, z[size], max, lamda, y[size], d[size], dmax;
    int n, i, k, j;
    cout << "Enter the number of unknowns: ";
    cin >> n;
    cout << "Enter the bound error: ";
    cin >> e;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]"
                 << ": ";
            cin >> a[i][j];
        }
    }
    cout <<endl<< "Enter matix X:" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "]"
             << "[" << 1 << "]"
             << ": ";
        cin >> x[i];
    }

    do
    {

        for (int i = 1; i <= n; i++)
        {
            z[i] = 0;

            for (int j = 1; j <= n; j++)
            {
                z[i] = z[i] + a[i][j] * x[j];
            }
        }

        max = z[1];
        for (int i = 1; i <= n; i++)
        {

            if (fabs(max) < fabs(z[i]))
            {
                max = z[i];
            }
        }
        lamda = max;
        for (int i = 1; i <= n; i++)
        {
            y[i] = z[i] / lamda;
        }
        for (int i = 1; i <= n; i++)
        {
            d[i] = fabs(y[i] - x[i]);
        }

        dmax = d[1];
        for (int i = 1; i <= n; i++)
        {

            if (dmax < d[i])
            {
                dmax = d[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            x[i] = y[i];
        }
    } while (dmax > e);

    cout << "Lamda" << lamda << endl;
    cout << "Solution: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << y[i] << endl;
    }
}
