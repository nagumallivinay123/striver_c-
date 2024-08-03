#include<bits/stdc++.h>
using namespace std;
int find_no_of_leap_years_before_given_year(int year){
    int some=year-1;
    cout<<(some/4-some/100+some/400)<<"\n";
}
int main(){

//leap year divisible by 4 avvali + okavela divisible by 100 ayyi ,divisible by 400 ayithe leap year avutadi .divisible by 100 ayyi ,divisbile by 400 avvakapothe adhi leap year kaadu  

int val=find_no_of_leap_years_before_given_year(2000);
cout<<val<<"\n";

return 0;
}