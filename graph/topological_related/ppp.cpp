class Solution
{
public:
    // map deniki anteh okavaipu level ,onkovaipu striing value store chesukuntamu
    //
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        string parent = word;
        for (int i = 0; i < parent.size(); i++)
        {
            char original = parent[i];
            for (char keep = 'a'; keep <= 'z'; keep++)
            {
                if (keep != original)
                {
                    parent[i] = keep;
                    if (mpp.find(parent) != mpp.end() && mpp[parent] + 1 = mpp[word])
                    {
                        seq.push_back(parent);
                        dfs(parent, seq);
                        seq.pop_back();
                    }
                }
            }
            parent[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<string> store;
        unordered_set<string> compare(wordList.begin(), wordList.end());
        store.push(beginWord);
        b = beginWord;
        compare.erase(beginWord);
        mpp[beginword] = 1;
        while (!store.empty())
        {
            string parent = store.front();
            int level = mpp[parent];
            if (parent == endWord)
            {
                break;
            }
            store.pop();
            for (int i = 0; i < parent.size(); i++)
            {
                char original = parent[i];
                for (char keep = 'a'; keep <= 'z'; keep++)
                {
                    if (keep != original)
                    {
                        parent[i] = keep;
                        if (compare.count(parent) > 0)
                        {
                            // parent ni findout chesamani ani ardam le
                            store.push(parent);
                            compare.erase(parent);
                            mpp[parent] = level + 1;
                        }
                    }
                }
                parent[i] = original;
            }
        }
        if (mpp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};