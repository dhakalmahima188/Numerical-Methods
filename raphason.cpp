#include<iostream>
#include<cmath>
using namespace std;
// #define f 3*x-cos(x)-10
// #define df 3*1-sin(x)

int func(double x)
{
    return 3*x-cos(x)-10;
}
int deriv(double x)
{
    return 3*1-sin(x);
}
int main(){
    double x0,x1,f0,f1,g0,e;
    int i=1,n;
    cout<<"Enter the initial value of x0: ";
    cin>>x0;
    cout<<"Enter tolerable error";
    cin>>e;
    cout<<"Iterations?";
    cin>>n;
    do{
        g0=deriv(x0);
        f0=func(x0);
        if(g0==0){
           cout<<"Error";
        }
        else{
             x1=x0-(f0/g0);
             x0=x1;
             i+=1;
             if(i>n){
                 cout<<"not converged";
             }
             else{
                 f1=func(x1);
             }
        }
    }while (fabs(f1)>e);
    {
        cout<<"The root is: "<<x1;
    }
    
}