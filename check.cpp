
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

using namespace std;

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(3) << fixed;

    /* Inputs */
    /* 1. Reading order of matrix */
    cout << "Enter order of matrix: ";
    cin >> n;

    /* 2. Reading Matrix */
    cout << "Enter coefficients of Matrix: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[" << i << "]" << j << "]= ";
            cin >> a[i][j];
        }
    }

    /* Augmenting Identity Matrix of Order n */
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
            {
                a[i][j + n] = 1;
            }
            else
            {
                a[i][j + n] = 0;
            }
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            exit(0);
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= 2 * n; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    /* Row Operation to Make Principal Diagonal to 1 */
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }
    }
    /* Displaying Inverse Matrix */
    cout << endl
         << "Inverse Matrix is:" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return (0);
}
