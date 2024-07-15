#include<bits/stdc++.h>
using namespace std;
//josephus problem o(N^2) solution  
int findTheWinner(int n, int k) 
    {
        vector<int>store(n,0);
        for(int i=0;i<n;i++){
            store[i]=i+1;
        }
        int index=0;
        //vadidi count chestamu kabatti 
        k--;
        while(store.size()>1)
        {
            index=(index+k)%store.size();
            store.erase(store.begin()+index);   
        }
        return store[0];
        
    }
int Josephus(int N, int k)
{

    // Initialize variables i and ans with 1 and 0
    // respectively.

    int i = 1, ans = 0;

    // Run a while loop till i <= N

    while (i <= N) {

        // Update the Value of ans and Increment i by 1
        ans = (ans + k) % i;
        i++;
    }

    // Return required answer
    return ans + 1;
}

//gurtupettuko ekkuva adagavachchu 
int josephus(int N, int k){
    if(N==1){
        return 1;
    }
    return josephus((N-1,k)+k-1)%N+1    ;
}


int main(){
return 0;
}