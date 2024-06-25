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
// lca concept ela anteh
// least common ancestor
// first step eppudu rendhu nodes yokka levels ni equal cheyali
// taravata binary search  lo binary veyali
// mundhu concepty vadatamu
// for each query (logN*LogN) avutundi

int parent[200001][20];
int level[200001];
void binary_lifting_form(int n, vector<int> &boss)
{
    memset(parent, -1, sizeof(int));
    for (int node = 1; node <= n; node++)
    {
        parent[node][0] = boss[node];
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
int query(int node, int index)
{
    if (node == -1)
    {
        return -1;
    }
    int some = index;
    int count = 0;
    while (some > 0)
    {
        if ((some & 1) == 1)
        {

            return query(parent[node][count], index - (1 << count));

            break;
        }
        some = some >> 1;

        count++;
    }

    return node;
}
void dfs(int index, int parent, int lev, vector<int> tree[], vector<int> &boss)
{
    level[index] = lev;
    boss[index] = parent;
    for (auto it : tree[index])
    {
        if (it != parent)
        {
            dfs(it, index, lev + 1, tree, boss);
        }
    }
    return;
}
// dinni complexity O()
int lca2(int node1, int node2)
{
    int a = level[node1];
    int b = level[node2];
    if (a > b)
    {
        swap(node1, node2);
    }
    node2 = query(node2, abs(a - b));
    if (node1 == node2)
    {
        return node1;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (parent[node1][i] != parent[node2][i])
        {
            node1 = parent[node1][i];
            node2 = parent[node2][i];
        }
    }
    return query(node1, 1);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> tree[n + 1];
    vector<int> bosses(n + 1, -1);
    bosses[1] = -1;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        // edhi graph kosam
        tree[a].push_back(b);
        tree[b].push_back(a);
        // edhi parent store chesukuntunna
    }
    dfs(1, -1, 0, tree, bosses);
    binary_lifting_form(n, bosses);
    while (q--)
    {
        int node1, node2;
        cin >> node1 >> node2;

        int LCA = lca2(node1, node2);
        cout << abs(2 * level[LCA] - level[node1] - level[node2]) << "\n";
    }
    // cout<<query(3,2)<<"\n";

    return 0;
}