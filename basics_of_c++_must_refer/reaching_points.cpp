#include<bits/stdc++.h>
using namespace std;
bool reach(int start_x,int start_y,int end_x,int end_y){
    if(start_x >end_x || start_y >end_y){return false;}
    if(start_x==end_x && start_y==end_y){
        return true;
    }
    if(end_x>end_y){
        return reach(start_x,start_y,end_x-end_y,end_y);
    }
    return reach(start_x,start_y,end_x,end_y-end_x);
}

int main(){
return 0;
}