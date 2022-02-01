#include <iostream>
using namespace std;
float func(float x, float y)
{
       return (y*y-x*x)/(y*y+x*x);
}
int main()
{
    int n;
    float x0, y0, xn, h, k1, k2, k, yn, k3, k4;
    cout << "Enter initial value :  x0,y0: ";
    cin >> x0 >> y0;
    cout << "Final value :  xn: ";
    cin >> xn;
    cout << "Enter no of steps: ";
    cin >> n;
    
    h = (xn - x0) / n;
    
    for (int i = 1; i < n; i++)
    {
        k1 = h * func(x0, y0);
        k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        k4 = h * func(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        cout<< x0<<"\t"<< y0<<"\t\t"<< yn<< endl;
        x0 = x0 + h;
        y0=yn;
    }
    cout << "The value of y is " << yn << endl;
}
