#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/********binary_lifting_concept**********/
// digit -> parent above
// 0-> 1
// 1-> 2
// 2-> 4
// 3-> 8
// 4-> 16
//...
//....

int parent[200001][20];
void binary_lifting_form(int n, vector<int> &boss)
{
    memset(parent, -1, sizeof(int));
    for(int node=1;node<=n;node++){
        parent[node][0]=boss[node];
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            // eg
            // index=4 ->above 16

            // parent[node][16]=parent{parent[node][8]}{8}
            // danne evidanga represent chestunnam
            // parent[node][4]=parent[parent[node][3]][3];
            if (parent[node][i - 1] != -1)
            {

               parent[node][i] = parent[parent[node][i - 1]][i - 1];
            }
            // enka paika vellipodam anteh akkadem undhavu
            else
            {
               parent[node][i] = -1;
            }
        }
    }
}
int query(int node,int index)
{
    if(node==-1){
        return -1;
    }
    int some=index;
    int count=0;
    while(some>0){
        if((some&1)==1)
        {
            
            return query(parent[node][count],index-(1<<count));
          
          
        }
        some=some>>1;
        
        count++;   
    }

    return node;
}

int main()
{
    int n,q;
    cin >> n>>q;
    // vector<int> tree[n + 1];
    vector<int> bosses(n + 1, -1);
    bosses[1] = -1;
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        // edhi graph kosam
        // tree[boss].push_back(i);
        // tree[i].push_back(boss);
        // edhi parent store chesukuntunna
        bosses[i] = boss;
    }
    binary_lifting_form(n,bosses);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<"\n";
    }
    // cout<<query(3,2)<<"\n";

    return 0;
}