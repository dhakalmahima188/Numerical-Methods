#include<iostream>
using namespace std;

float func(float x,float y){
    return -2*x-y;
}

int main(){
       float x0,y0,h,x;
    cout<<"Enter initial value of x0,y0"<<endl;
    cin>>x0>>y0;
    cout<<"Enter the value of  for which y is to be determined";
    cin>>x;
    cout<<"Enter the width of the interval";
    cin>>h;
    float y1,y2,y3;
    while(x0<x){
        y1=y0+h*func(x0,y0);       
        y0=y1;
        x0=x0+h;
    }
    cout<<"The value of y is "<<y0<<endl;
    return 0;

}