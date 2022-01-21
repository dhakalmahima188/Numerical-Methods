#include <iostream>
#include <cmath>
#define size 10
using namespace std;
int main()
{
    float a[size][size], temp, ans,sum=0,x[size];
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
    for (j = 1; j <= n-1; j++)
    {
        for (i = j+1; i <= n; i++)
        {
            temp = a[i][j];
            
         
            for (k = j; k <= n + 1; k++)
            {
               
         a[i][k] = a[i][k] -( (temp / a[j][j]) * a[j][k]);
                }
            
            
            }
        
    }
    for (i = n; i >= 1; i--)
    {
        sum=0;
        for (j = i+1; j <= n; j++)
        {

            sum=sum+a[i][j]*x[j];

            
        }
        x[i]=(a[i][n+1]-sum)/a[i][i];
       
    }
     for(i=1;i<=n;i++){
        cout<<"Solution is: "<<x[i]<<endl;}
}