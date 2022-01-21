#include <iostream>
#include <cmath>
#define size 10
using namespace std;
int main()
{
    float a[size][size], temp, ans;
    int n, i, k, j;
    cout << "Enter the number of unknowns: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]"<<": ";
            cin >> a[i][j];
        }
    }
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            temp = a[i][j];
            
            if (i != j){
            for (k = 1; k <= n + 1; k++)
            {
               
         a[i][k] = a[i][k] -( (temp / a[j][j]) * a[j][k]);
                }
            
            
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {

            if (i == j)
            {

                ans = a[i][n + 1] / a[i][i];
                cout << "solution: "<< ans<<endl;
            }
        }
    }
}