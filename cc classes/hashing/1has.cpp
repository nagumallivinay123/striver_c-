#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int a[10];//global lo eppudaina declare cheste dani intial value zero vastundi
//edi main ga ekkada ante frequency repetation lo vadatamu
//edi precomputation technicques ane cheppavachchu
int main(){
//example
int arr[10]={2,4,5,4,4,5,6,6,8,9};
//endulo enni frequencies unnayo kanukovali ante
for(int i=0;i<10;i++){
    a[arr[i]]++; 
}
for(int i=0;i<10;i++){
    cout<<a[i]<<endl;
}


return 0;}