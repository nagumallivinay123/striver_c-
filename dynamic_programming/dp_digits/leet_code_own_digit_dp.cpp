
//leetcode problem edhi -> https://leetcode.com/contest/biweekly-contest-121/problems/count-the-number-of-powerful-integers/
//first time digit dp type sum naa own gaa mottam code raasa 
//bool borrow logic ekkada nunchi vachchindi anteh kartik arora digit dp nunchi vacchichindi 
//katrik arrora reference -> https://www.youtube.com/watch?v=lD_irvBkeOk&list=RDCMUCJZF4VOyV9zfm2SH_QdeOWw&index=3

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long func(string &s, string &match, int s_index, int match_index, int &limit,bool borrow)
    {
        if (s_index < 0)
        {
            if (borrow)
                return 0;
            return 1;
        }
        long long ans = 0;
        if (match_index >= 0)
        {

            int a = s[s_index] - '0';
            int b = match[match_index] - '0';
            if (borrow)
            {
                if (a == 0)
                {
                    borrow = true;
                    a = 9;
                }
                else
                {
                    a = a - 1;
                    borrow = false;
                }
            }

            if (a >= b)
            {
                ans = func(s,  match, s_index - 1, match_index- 1,limit, borrow);
            }
            else
            {
                ans = func(s,  match, s_index - 1, match_index - 1 ,limit,true);
            }
        }

        else
        {
            int a = s[s_index] - '0';
            if (borrow)
            {
                if (a == 0)
                {
                    borrow = true;
                    a = 9;
                }
                else
                {
                    a = a - 1;
                    borrow = false;
                }
            }
            if (a >= limit)
            {
                ans += ((limit + 1) * func(s, match, s_index - 1, match_index,limit, borrow));
            }
            else
            {
                ans += (a + 1) * func(s, match, s_index - 1, match_index,limit, borrow);
                ans += (limit - a) * func(s, match, s_index - 1, match_index,limit, true);
            }
        }

        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string match)
    {
        // digit dp
        string r = to_string(finish);
        string l = to_string(start-1);
        bool check_r = r.length() < match.length() ? 0 : 1;
        bool check_l = l.length() < match.length() ? 0 : 1;
        long long right = 0;
        long long left = 0;
        if (check_r)
        {
            right = func(r, match, r.length() - 1, match.length() - 1, limit,false);
        }
        if (check_l)
        {
            
            left = func(l, match, l.length() - 1, match.length() - 1,limit, false);
        }
        return right - left;
    }
};
int main()
{




return 0;
}