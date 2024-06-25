#include <iostream>
#include <bits/stdc++.h>
// enni cycles unnayi
// better standing check luv agarawal 2.5x lo chudu
using namespace std;
const int n = 1e3;
vector<vector<int>> v(n);
vector<bool> vertex(n, false);
bool modified_dfs(int node, int parent)
{
    vertex[node] = true;
    bool check = false;
    for (int i = 0; i < v[node].size(); i++)
    {
        // edhi dfs lo manam vertex of child true ayyi adhi parent ayithe adhi cycle lekka loki radhu kada
        if (vertex[v[node][i]] == true && v[node][i] == parent)
            continue;
        // edhi dfs lo child nuvvu malli chustunnavu ante akkada cycle exist avutunnate kada
        // mottam graph lo okka cycle chusina mottam chusinatte kada
        if (vertex[v[node][i]] == true)
            return true;
        check |= modified_dfs(v[node][i], node);
    }
    return check;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool chek = false;
    for (int i = 1; i <= n; i++)
    {
        if (vertex[i] == true)
            continue;
        if (modified_dfs(i, 0) == true)
        {
            chek = true;
            cout << "yes";
            break;
        }
    }
    if (chek == false)
    {
        cout << "no"
             << "\n";
    }
    return 0;
}