#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ekkada summation segment tree
// summation segment tree anteh range of[L R ] nunchi summation of that array teesukuntamu
class SGTree
{
    // seg annadi private lo untaadi
    vector<int> seg;

public:
    SGTree(int n)
    {
        // array size n unteh segment size annadi 4*n undali

        seg.resize(4 * n + 1);
    }
    // segment tree built cheyadaniki
    // segment tree building time complexity o(4*n)
    // O(4*n) size node fill chestunnavu
    void build(int index, int low, int high, vector<int> &arr)
    {
        // base case
        if (low == high)
        {
            if (low == 0 || low == n - 1)
            {
                seg[index] = 0;
            }
            else
            {
                if (arr[low] > arr[low - 1] && arr[low] > arr[low + 1])
                {
                    seg[index] = 1;
                }
            }

            return;
        }
        int mid = (low + high) / 2;
        // tree lo index ki left index 2*index+1
        build(2 * index + 1, low, mid, arr);
        // tree lo index ki right index 2*index+2;
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = (seg[2 * index + 1] + seg[2 * index + 2]);
    }

    void update(int index, int low, int high, int given_update_index, int val, vector<int> &arr)
    {
        // it is base case
        // given_update_array index reach ayipoyavu ani ardam, so value update  chestavu
        if (high == low)
        {
            if (low == 0 || low == n - 1)
            {
                seg[index] = 0;
            }
            else
            {

                arr[low] = val;
                if (arr[low] > arr[low - 1] && arr[low] > arr[low + 1])
                {
                    seg[index] = 1;
                }
            }

            return;
        }
        int mid = (low + high) >> 1;
        if (given_update_index <= mid)
        {
            update(2 * index + 1, low, mid, given_update_index, val, arr);
        }
        else
        {
            update(2 * index + 2, mid + 1, high, given_update_index, val, arr);
        }
        seg[index] = (seg[2 * index + 1] + seg[2 * index + 2]);
    }
    int query(int index, int low, int high, int given_l, int given_r)
    {

        // no overlap
        //[given_l given_r][low high] or [low high][given_l given_r]
        if (given_r < low || high < given_l)
        {
            return 0;
        }
        // complete overlap
        //[given_l low high given_r]
        if (given_l <= low && high <= given_r)
        {
            return seg[index];
        }
        int mid = (low + high) / 2;
        int left = query((2 * index + 1), low, mid, given_l, given_r);
        int right = query((2 * index + 2), mid + 1, high, given_l, given_r);
        return left + right;
        // partial overlap
    }
    void print()
    {
        for (auto it : seg)
        {
            cout << it << " ";
        }
    }
};

int main()
{

    return 0;
}