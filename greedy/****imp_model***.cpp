//https://www.geeksforgeeks.org/problems/water-the-plants--170646/1

 
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>>store;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
                int lower=max(0,i-gallery[i]);
                int upper=min(n,i+gallery[i]);
                store.push_back({lower,upper});
                // cout<<lower<<upper<<"\n";
            }
        }
        sort(store.begin(),store.end());
        if(store.empty() || store.begin()->first>0){
            return -1;
        }
       
        int start=0;
        int i=0;
        int ans=0;
        //main gaa ee logic baaga important jagrathaga chusuko 
        while(start<n)
        {
            int maxi=INT_MIN;
            while(i<store.size())
            {
                if(store[i].first>start){
                    break;
                }
                maxi=max(store[i].second,maxi);
                i++;
            }
            if(start>maxi){
                return -1;
            }
            ans++;
            start=maxi+1;
        }
        return ans;
    }