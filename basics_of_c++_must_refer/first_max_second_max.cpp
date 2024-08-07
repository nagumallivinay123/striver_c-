#include<bits/stdc++.h>
using namespace std;
int main(){
    int first_max=-1;
    ins second_max=-1;
    vector<int>a;
    for(int i=0;i<10;i++){
        a.push_back(i+1);
    }
    //e logic annadi chaala important baaga 
    for(int i=0;i<10;i++){
        if(a[i]>first_max){
            //ekkada exchange avutundi 
            second_max=first_max;
            first_max=a[i];
        }
        else if(a[i]>second_max){
            second_max=a[i];
        }
    }


return 0;
}