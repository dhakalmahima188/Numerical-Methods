#include <iostream>
#define max 20
#include <cmath>
using namespace std;
float func(float x)
{
    return x*x*x - 2 * x*x- 5;
}
int main()
{
    int count = 0;
    float a, b, e, c;
    cout << "Intial guess: a b and tolerance ";
    cin >> a >> b >> e;
    try
    {
        do
        {
            if (func(a) == func(b))
            {
                throw "mathematical error";
            }
            else
            {
                count = count + 1;
                if (count > max)
                {
                    throw "maximum iteration reached";
                    
                }
                c = (a * func(b) - b * func(a)) / (func(b) - func(a));
                a = b;
                b = c;
            }
        } while (fabs(func(c)) > e);
        cout << "root is : " << c;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
}