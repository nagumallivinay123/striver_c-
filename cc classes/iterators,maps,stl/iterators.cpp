#include <iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
#include<cmath>
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
using namespace std;

int main(){
//timpe complexity is  logn;
 map<string,string>vinay;
 vinay["100"]="hundered";
 vinay["1000"]="thousands";
 vinay.insert(pair<string,string>("iiita","allahabad"));
 vinay.insert(pair<string,string>("iith","hyderabad"));
cout<<vinay["iith"]<<endl;
cout<<(*vinay.find("iith")).first<<endl;;
cout<<(*vinay.find("iith")).second;
for(auto itr=vinay.begin();itr!=vinay.end();itr++){
    cout<<itr->first<<" "<<itr->second<<endl;
}
for(pair<string,string>x:vinay){
    cout<<x.first<<x.second<<endl;

}

return 0;
}