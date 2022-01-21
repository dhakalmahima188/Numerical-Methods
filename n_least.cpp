// least square curve fitting
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x[10], y[10], sum[10][10], tsum, temp, b,ans;
    int i, j, k, num,n,d;
    cout<<"Enter the degree: ";
    cin>>d;
    n=d+1;
    cout << "Enter the no of data: ";
    cin >> num;
    cout << "PLease enter values: " << endl;
    cout << "Enter x: " << endl;
    for (k = 0; k < num; k++) cin >> x[k];
    cout << "Enter y: " << endl;
    for (k = 0; k < num; k++) cin >> y[k];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tsum = 0;
            for (int k = 0; k < num; k++) {
                tsum = tsum + pow(x[k], i + j);
                //     cout<<"TSum: "<<tsum;
            }
            sum[i][j] = tsum;
        }
    }
    
    for (int i = 0; i < n; i++) {
        tsum = 0;
        for (int k = 0; k < num; k++) tsum = tsum + pow(x[k], i) * y[k];
        sum[i][n] = tsum;
    }
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
            cout << sum[i][j] << "\t\t ";
        cout << endl;
    }
    
    // Gauss Jordan Method
    cout << "Applying Gauss Jordan Method" << endl;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            temp = sum[i][j] / sum[j][j];
            if (i != j) {
                for (k = 0; k < n + 1; k++) 
                sum[i][k] -= temp  * sum[j][k];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                ans = sum[i][n] / sum[i][i];
                cout << "a[" << i << "]: " << ans << endl;
            }
        }
    }
}