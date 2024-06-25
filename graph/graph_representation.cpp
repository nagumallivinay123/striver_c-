#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<vector<int> > graph1(N);
vector<pair<int, int> > graph2(N);
int main()
{
    // graph ni ela represent chestamu
    // dms subject lo adjacentary matrix dwara ela connect chestamo ekkada kuda alane chestamu
    // manam vector vade ekkuva questionchestamu
    // adjancey weighted graph lo store chestamu endhuku ala ante i+j chestamu kada
    int n, m;
    cin >> n >> m; // vertices and edges data lo teeskutamu;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph1[v2].push_back(v1);
        graph2.push_back(pair<int, int>(v2, v1 + v2)); // weighted kada andhuku
    }
    for(int i=0;i<graph1[1].size();i++){
        cout<<graph1[1][i];
    }

    return 0;
}