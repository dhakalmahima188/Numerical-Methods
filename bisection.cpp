#include <iostream>
#include <cmath>
using namespace std;
float func(float x)
{
    return x * sin(x) + cos(x);
}
float der(float x)
{
    return x * cos(x);
}

int main()
{

    float f, df, x0, e, x1, flag;
    int n = 20;
    cout << "Enter the initial guess of x: ";
    cin >> x0;
    cout << "Please enter Error? ";
    cin >> e;

    do
    {
        try
        {

            if (fabs(der(x0)) < 5E-10)
            {
                cout << "Discontinious!!" << endl;
                throw("Discontinious!!");
            }
            x1 = x0 - (func(x0) / der(x0));
            x0 = x1;
        }

        catch (char *error)
        {
            cout << error;
        }
    } while (!(fabs(func(x0)) < e));

    cout << "Root: " << x0;
}
