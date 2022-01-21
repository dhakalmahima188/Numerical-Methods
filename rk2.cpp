#include<iostream>
using namespace std;

float func(float x,float y){
    return y*x+y*y;
}
int main(){
    int n;
    float x0,y0,xn,h,k1,k2,k,yn;
    cout<<"Enter initial value of x0,y0"<<endl;
    cin>>x0>>y0;
    cout<<"final value of xn";
    cin>>xn;
    cout<<"Enter no of steps";
    cin>>n;
    h=(xn-x0)/n;
    for(int i=1; i<n;i++)
    {
        k1=h*func(x0,y0);
        k2=h*func(x0+h,y0+k1);
        k=(k1+k2)/2;
        yn=y0+k;
        x0=x0+h;
        y0=yn;
    }
    cout<<"The value of y is "<<yn<<endl;

}