class Solution {
public:
//edhi ayithe chaala imp ...
    int max_area_rectangle(vector<int>&hist){
        int n=hist.size();
        stack<int>store;
        int max_area=0;
        for(int i=0;i<=n;i++){
            while(!store.empty() && (i==n || hist[store.top()]>=hist[i]))
            {
                int height=hist[store.top()];
                store.pop();
                int width;
                if(store.empty()){
                    width=i;
                }
                else{
                  width=i-store.top()-1;
                }
                max_area=max(max_area,(width*height));
                
            }
            store.push(i);
        }
        return max_area;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //striver cheppina max_area_sum ki related adhi 
        //doubt vaste edhi chudu -> https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/
        //max area 
        //https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
        //
        //first histogram  kannuko 
        int n=matrix.size();
        int m=matrix[0].size();
        int max_ans=0;
        vector<int>hist(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    // cout<<"some";
                    hist[j]=hist[j]+1;
                }
                else{
                    hist[j]=0;
                }
            }
            for(auto it:hist){
                cout<<it<<" ";
            }
            cout<<"\n";
            int temp=max_area_rectangle(hist);
            max_ans=max(max_ans,temp);

            
        }
        return max_ans;
        
    }
};