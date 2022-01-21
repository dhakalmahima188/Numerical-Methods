#include <iostream>
#include <cmath>
#define size 10
using namespace std;

int main()
{
    float a[size][size], x[size], temp, ans;
    int n, i, k, j;
    cout << "Enter the number of unknowns: ";
    cin >> n;
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
    for (i = 1; i <= n; i++)
    {
        for (j = n+1; j <=2* n; j++)
        {
            if (i == j - n)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    for (j = 1; j <= n; j++)
    {
        if (a[j][j] == 0)
        {
            cout << "The system is inconsistent" << endl;
            exit(0);
        }
        for (i = 1; i <= n; i++)
        {
            temp = a[i][j];

            if (i != j)
            {
                for (k = 1; k <= 2 * n; k++)
                {

                    {
                        a[i][k] = a[i][k] - ((temp / a[j][j]) * a[j][k]);
                    }
                }
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = n+1; j <=2* n; j++)
        {

            a[i][j] = a[i][j] / a[i][i];
            
        }
    }

    cout << endl
         << "Solution: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {

            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

