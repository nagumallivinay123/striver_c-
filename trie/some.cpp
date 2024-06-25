class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        queue<string> store;
        vector<string> out;
        int sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int a = words[i].length();
            if (a + sum > maxWidth)
            {
                int m = store.size();
                if (m == 1)
                {
                    string u = store.front();
                    int l = u.length();
                    while (l < maxWidth)
                    {
                        u += " ";
                        l++;
                    }

                    out.push_back(u);
                    store.pop();
                }

                else
                {

                    string ans = "";
                    int spaces = maxWidth - (sum - (m));
                    int equal = (spaces) % (m - 1);
                    int each = spaces / (m - 1);
                    int count = 1;
                    if (equal != 0)
                    {
                        int left = m - 2 > 0 ? spaces / (m - 2) : spaces / 2 + 1;
                        int right = m - 2 > 0 ? spaces % (m - 2) : spaces / 2;
                        while (!store.empty())
                        {
                            string u = store.front();
                            store.pop();
                            if (count == m)
                            {
                                ans += u;
                                break;
                            }

                            ans += u;
                            for (int i = 0; i < left; i++)
                            {
                                if (count == m - 1)
                                {
                                    if (i >= right)
                                    {
                                        break;
                                    }
                                }
                                ans += " ";
                            }

                            count++;
                        }
                    }

                    while (!store.empty())
                    {
                        string u = store.front();
                        store.pop();
                        if (count == m)
                        {
                            ans += u;
                            break;
                        }
                        ans += u;
                        for (int i = 0; i < each; i++)
                        {
                            ans += " ";
                        }

                        count++;
                    }
                    out.push_back(ans);
                }

                sum = 0;
            }
            store.push(words[i]);
            sum += (a + 1);
        }
        if (!store.empty())
        {
            int m = store.size();
            if (m == 1)
            {
                string u = store.front();
                int l = u.length();
                while (l < maxWidth)
                {
                    u += " ";
                    l++;
                }

                out.push_back(u);
                store.pop();
            }
            else
            {
                string ans = "";
                int spaces = maxWidth - (sum - (m));
                int equal = (spaces) % (m - 1);
                int each = spaces / (m - 1);
                int count = 1;
                if (equal != 0)
                {
                    each = 1;
                }
                while (!store.empty())
                {
                    string u = store.front();
                    store.pop();
                    if (count == m)
                    {
                        ans += u;
                        break;
                    }
                    ans += u;
                    for (int i = 0; i < each; i++)
                    {
                        ans += " ";
                    }

                    count++;
                }
                int l = ans.length();
                while (l < maxWidth)
                {
                    ans += " ";
                    l++;
                }

                out.push_back(ans);
            }
        }
        return out;
    }
};