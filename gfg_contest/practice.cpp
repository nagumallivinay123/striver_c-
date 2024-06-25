
#include <bits/stdc++.h>
using namespace std;
class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {

        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {

            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    vector<int> CompatibleStrings(int N, vector<string> &A1, vector<string> &A2)
    {
        // code here
        vector<int> ans(N, 0);
        for (int l = 0; l < N; l++)
        {
            string a = A2[l];
            string b = A1[l];
            vector<int> store1(26, 0);
            vector<int> store2(26, 0);
            vector<int> require(26, 0);
            int gcd_require = -1;
            int gcd_sub = -1;

            for (int j = 0; j < a.length(); j++)
            {
                store1[a[j] - 'a']++;
                store2[b[j] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (store1[i] != 0 || store2[i] != 0)
                {
                    if (store2[i] >= store1[i])
                    {
                        store2[i] -= store1[i];
                        if (store2[i] != 0)
                        {
                            gcd_sub == -1 ? gcd_sub = store2[i] : gcd_sub = gcd(gcd_sub, store2[i]);
                        }
                    }
                    else
                    {
                        require[i] = store1[i] - store2[i];
                        if (require[i] != 0)
                        {
                            gcd_require == -1 ? gcd_require = store2[i] : gcd_require = gcd(gcd_require, require[i]);
                        }
                    }
                }
            }
            int gcd_common = gcd(gcd_sub, gcd_require);
            if (gcd_require == -1 && gcd_sub == -1)
            {
                ans[l] = 1;
            }
            else if (gcd_sub == 1 || gcd_require == 1 || gcd_common == 1)
            {
                ans[l] = 0;
            }
            else
            {
                bool find = true;
                for (int i = 0; i < 26; i++)
                {
                    if (require[i] == 0)
                    {
                        continue;
                    }

                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (store2[j] == 0)
                        {
                            continue;
                        }
                        if (require[i] > store2[j])
                        {
                            require[i] -= store2[j];
                            store2[j] = 0;
                        }
                        else
                        {
                            store2[j] -= require[i];
                            require[i] = 0;
                            break;
                        }
                    }
                    if (require[i] != 0)
                    {
                        find = false;
                        break;
                    }
                }
                if (find)
                {
                    ans[l] = 1;
                }
            }
        }
        return ans;
    }
};
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        vector<string> A1(N), A2(N);
        for (int i = 0; i < N; i++)
            cin >> A1[i];
        for (int i = 0; i < N; i++)
            cin >> A2[i];
        Solution obj;
        vector<int> res = obj.CompatibleStrings(N, A1, A2);
        Array::print(res);
    }
}