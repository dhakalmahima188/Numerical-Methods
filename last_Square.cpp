#include <iostream>
using namespace std;
int getsum(int *x)
{
    int sum;
    for (int i = 0; i < 10; i++)
    {
        cin >> x[i];
        sum = sum + x[i];
    }

    return sum;
}

int main()
{
    int n, x[10], y[10], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;
    float a,b;
    cout << "Enter x: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> x[i];
        sumx = sumx+ x[i];
        sumx2=sumx2+(x[i]*x[i]);
    }
    cout << "Enter y: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> y[i];
        sumy=sumy+y[i];
    }

       for (int i = 0; i < 5; i++)
    {
       
        sumxy=sumxy+y[i]*x[i];
    }


 a=(sumy*sumx2-sumxy*sumx)/(n*sumx2-sumx*sumx);
 b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
 cout<<"The value of a: "<<a<<endl;
  cout<<"The value of b: "<<b;

}