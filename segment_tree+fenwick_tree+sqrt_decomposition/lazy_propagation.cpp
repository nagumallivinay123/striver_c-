#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// lazy_propagation->range update
// endaka segment_tree lo kevalam point update matrame echchadu
// adeh okavela range update ayithe ->  [L R] madya lo echchadu anteh aa range mottaniki nuvvu update cheyalanthe time complexity o((L-R)*logn) avutundi ->o(Log n)
// range update kosame lazy propagation puttindi

// lazy propgation -> baddakam further gaa update cheyadaniki

// segment tree for summation for given range
class SGTree
{
    vector<int> seg, lazy;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1,0);
        lazy.resize(4 * n + 1, 0);
    }
    void build(int index, int low, int high, int arr[])
    {
        // base case
        if (low == high)
        {
            seg[index] = arr[low];
            return ;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }


    // range update lo eppudu
    void range_update(int index, int low, int high, int given_l, int given_r, int val)
    {
        // first update seg[index] value from lazy[index] if lazy[index]!=0
        if (lazy[index] != 0)
        {
            // you should update segment value
            seg[index] += (high - low + 1) * lazy[index];
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
            lazy[index] = 0;
        }
        // three cases
        // 1->no overlap
        //[low high][given_l given_r] or [given_l given_r][low high]
        if (high < given_l || given_r < low)
        {
            return;
        }

        // 2-> complete overlap
        //  [ given_l low high given_r]
        if (given_l <= low && high <= given_r)
        {
            seg[index] += (high - low + 1) * val;
            // children ki manam pass chestunam aa value ni (endhukanteh further ki use avathadi )
            // downward propagation
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }

        // 3->partial overlap
        int mid = (low + high) >> 1;
        range_update(2 * index + 1, low, mid, given_l, given_r, val);
        range_update(2 * index + 2, mid + 1, high, given_l, given_r, val);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
    int query(int index, int low, int high, int given_l, int given_r)
    {
        // first update seg[index] value from lazy[index] if lazy[index]!=0
        if (lazy[index] != 0)
        {
            // you should update segment value
            seg[index] += (high - low + 1) * lazy[index];
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
            lazy[index] = 0;
        }
        // three cases
        // 1->no overlap
        //[low high][given_l given_r] or [given_l given_r][low high]
        if (high < given_l || given_r < low)
        {
            return 0;
        }
        // 2-> overlap
        //[given_l low high given_r]
        if (given_l <= low && high <= given_r)
        {
            return seg[index];
        }
        // 3->partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * index + 1, low, mid, given_l, given_r);
        int right = query(2 * index + 2, mid + 1, high, given_l, given_r);
        return left + right;
    }
};

// segment tree for minimum value for given range

class SGTree2
{
    vector<int> seg, lazy;

public:
    SGTree2(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }
    void build(int index, int low, int high, int arr[])
    {
        // base case
        if (low == high)
        {
            seg[index] = arr[low];
            return ;
        }
        int mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
    // range update lo eppudu
    void range_update(int index, int low, int high, int given_l, int given_r, int val)
    {
        // first update seg[index] value from lazy[index] if lazy[index]!=0
        if (lazy[index] != 0)
        {
            // you should update segment value
            seg[index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
            lazy[index] = 0;
        }
        // three cases
        // 1->no overlap
        //[low high][given_l given_r] or [given_l given_r][low high]
        if (high < given_l || given_r < low)
        {
            return;
        }

        // 2-> complete overlap
        //  [ given_l low high given_r]
        if (given_l <= low && high <= given_r)
        {
            seg[index] += val;
            // children ki manam pass chestunam aa value ni (endhukanteh further ki use avathadi )
            // downward propagation
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }

        // 3->partial overlap
        int mid = (low + high) >> 1;
        range_update(2 * index + 1, low, mid, given_l, given_r, val);
        range_update(2 * index + 2, mid + 1, high, given_l, given_r, val);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
    int query(int index, int low, int high, int given_l, int given_r)
    {
        // first update seg[index] value from lazy[index] if lazy[index]!=0
        if (lazy[index] != 0)
        {
            // you should update segment value
            seg[index] += (high - low + 1) * lazy[index];
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
            lazy[index] = 0;
        }
        // three cases
        // 1->no overlap
        //[low high][given_l given_r] or [given_l given_r][low high]
        if (high < given_l || given_r < low)
        {
            return 0;
        }
        // 2-> overlap
        //[given_l low high given_r]
        if (given_l <= low && high <= given_r)
        {
            return seg[index];
        }
        // 3->partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * index + 1, low, mid, given_l, given_r);
        int right = query(2 * index + 2, mid + 1, high, given_l, given_r);
        return min(left, right);
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    // ekkada summation segment tree chestunnam
    SGTree sg(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout<<arr[i]<<" ";
    }
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        // type ==1 it is query
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << "\n";
        }
        // type==2 it is update
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            sg.range_update(0, 0, n - 1, l, r, val);
        }
    }

    return 0;
}