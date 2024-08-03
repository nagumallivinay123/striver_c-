#include<bits/stdc++.h>
using namespace std;

class solution{
  public:
    
    int alternatingMaxLength(vector<int>& arr) {
        //ee logic teliyaka chaala ibandi padda 
        //enchuumnchu 1hr paddadi 
        //Why this works:
// - At each step, we're effectively considering two possible alternating subsequences:
//   1. One that ends with an upward trend
//   2. One that ends with a downward trend
// - By updating these lengths based on the current element's relation to the previous element, we ensure that we're always tracking the longest possible alternating subsequence up to that point.
        int increase=1;
        int decrease=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]){
                increase=decrease+1;
            }
            else if(arr[i]<arr[i-1]){
                decrease=increase+1;
            }
        }
        return max(increase,decrease);
        
    }
};