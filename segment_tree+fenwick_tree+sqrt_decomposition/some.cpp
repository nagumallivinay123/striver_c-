#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> tree;
    int size;

    SegmentTree(int n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }

    void build(const vector<int> &a, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(a, 2 * node + 1, start, mid);
            build(a, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    void update(int idx, int value, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = value;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(idx, value, 2 * node + 1, start, mid);
            }
            else
            {
                update(idx, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    int query(int l, int r, int node, int start, int end)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(l, r, 2 * node + 1, start, mid);
        int right = query(l, r, 2 * node + 2, mid + 1, end);
        return left | right;
    }
};

int get_ans(int n, int k, vector<int> a, int three,vector<vector<int>> queries)
{
    int max_val = (1 << k) - 1; // 2^k - 1
    int result = 0;

    SegmentTree segTree(n);
    segTree.build(a, 0, 0, n - 1);

    for (const auto &query : queries)
    {
        if (query[0] == 1)
        {
            // Type 1: Update the array
            int index = query[1] - 1; // Convert to 0-based index
            int value = query[2];
            segTree.update(index, value, 0, 0, n - 1);
        }
        else if (query[0] == 2)
        {
            // Type 2: Find the shortest subarray
            int l = query[1] - 1; // Convert to 0-based index
            int r = query[2] - 1;
            int min_length = INT_MAX;
            bool found = false;

            int start = l;
            while (start <= r)
            {
                int low = start, high = r, best = -1;
                while (low <= high)
                {
                    int mid = (low + high) / 2;
                    if (segTree.query(start, mid, 0, 0, n - 1) == max_val)
                    {
                        best = mid;
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                if (best != -1)
                {
                    min_length = min(min_length, best - start + 1);
                    found = true;
                }
                ++start;
            }

            if (found)
            {
                result += min_length;
            }
        }
    }

    return result;
}

int main()
{
    // Example input
    int n = 3;
    int k = 3;
    vector<int> a = {2, 2, 4};
    vector<vector<int>> queries = {
        {1, 1, 1},
        {2,1, 3}};

    cout << get_ans(n, k, a,3, queries) << endl;

    return 0;
}
