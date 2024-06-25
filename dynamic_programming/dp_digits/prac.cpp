class Solution
{
public:
    long long func(string &s, int &limit, string &match, int i, int j, bool borrow)
    {
        if (i < 0)
        {
            if (borrow)
                return 0;
            return 1;
        }
        long long ans = 0;
        if (j >= 0)
        {

            int a = s[i] - '0';
            int b = match[i] - '0';
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
                ans = func(s, limit, match, i - 1, j - 1, borrow);
            }
            else
            {
                ans = func(s, limit, match, i - 1, j - 1, true);
            }
        }

        else
        {
            int a = s[i] - '0';
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
                ans += ((limit + 1) * func(s, limit, match, i - 1, j, borrow));
            }
            else
            {
                ans += (a + 1) * func(s, limit, match, i - 1, j, borrow);
                ans += (limit - a) * func(s, limit, match, i - 1, j, true);
            }
        }

        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string match)
    {
        // digit dp
        string r = to_string(finish);
        string l = to_string(start);
        bool check_r = r.length() < s.length() ? 0 : 1;
        bool check_l = l.length() < s.length() ? 0 : 1;
        long long right = 0;
        long long left = 0;
        if (check_r)
        {
            right = func(r, limit, s, r.length() - 1, match.length() - 1, false);
        }
        if (check_l)
        {
            left = func(l, limit, s, l.lenghth() - 1, match.length() - 1, false);
        }
        return right - left;
    }
};