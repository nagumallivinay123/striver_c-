#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const double compare=1e-7;
double sqrt_binary_search(double value){
    double lower=0;
    double upper=value;
    while(upper-lower>compare)
    {
        double mid=(upper+lower)/2;
        if(mid*mid<value){
            lower=mid;
        }
        else{
            upper=mid;
        }
    }
    return lower;
}
//edhe vidanga any power ayina cheyavachchu
int main(){
int x;
cin>>x;
cout<<pow(x,0.5)<<"\n";
cout<<setprecision(6)<<sqrt_binary_search(x)<<"\n";



return 0;}