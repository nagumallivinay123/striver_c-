#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//LINE SWEEP

//reference question leet code  -> https://leetcode.com/problems/maximum-population-year/
//***imp logic***
//chaala **line sweep algorithm ***
//ekkuva intervals echchi maximum numbers of time repeated ayinavatiki edhi vadatamu 
//harsha gadu cheppina +1 and -1 logic on maps chesi cheste ayipothadi
 int maximumPopulation(vector<vector<int>>& logs) 
    {

        //harsha gaadu cheppina logic +1 -1 
        //reference edhi teesukunnanu 
        //https://www.youtube.com/watch?v=WsNlv1Lr94I
        map<int,int>mp;
        for(int i=0;i<logs.size();i++){
            int birth=logs[i][0];
            int death=logs[i][1];
            mp[birth]++;
            mp[death]--;
        }
        int max_count=INT_MIN;
        int max_count_year=1950;
        int count=0;
        for(auto it:mp){
              count+=it.second;
              if(count>max_count){
                  max_count=count;
                  max_count_year=it.first;
              }
        }
        return max_count_year;
    } 
int main(){



return 0;}