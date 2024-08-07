#include<bits/stdc++.h>
using namespace std;

//leetcode problem edhi 
//edhi kuda trie alochana ventane ravali 

struct Node {
  Node *bits[2];
  Node(){
    bits[0]=NULL;
    bits[1]=NULL;
  }
  bool present(int given_bit){
    return bits[given_bit]!=NULL;
  }
  void put(int bit,Node *s){
    bits[bit]=s;
    
  }
  Node *get_next_ref(int bit){
       return bits[bit];
  }
};
class trie{
    Node *root;
    public:
    trie(){
        root=new Node();
    }
    void put(int num)
    {
        Node *current=root;
        for(int i=31;i>=0;i--){
            int match_bit=((num>>i)&1);
            if(!current->present(match_bit))
            {
                current->put(match_bit,new Node());
            }
            current=current->get_next_ref(match_bit);   
        }
    }
    int find_max(int num){
        Node *current=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int match_bit=((num>>i)&1);
            int opp_match_bit=1-match_bit;
            if(current->present(opp_match_bit)==true){
                 ans=ans| (1<<i);
                 current=current->get_next_ref(opp_match_bit);
            }
            else{
                current=current->get_next_ref(match_bit);
            }
 
        }
        return ans;
    }


};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
    {
        trie some;
        int q=queries.size();
        int n=nums.size();
        vector<int>ans(q,0);
        vector< pair<pair<int,int>,int> >store;
        int index=0;
        for(auto it:queries){
            store.push_back({{it[1],it[0]},index});
            index++;
        }
        sort(store.begin(),store.end());
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<queries.size();i++){
            while(j<n && nums[j]<=store[i].first.first){
                some.put(nums[j]);
                j++;
            }
            int maxi=-1;
            if(j>0){
             maxi=some.find_max(store[i].first.second);
            }
            ans[store[i].second]=maxi;
        }



        return ans;



        
    }
};
int main()
{



}