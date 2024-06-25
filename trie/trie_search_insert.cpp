// trie anteh adoka struct main gaa mundu insert chesina vi search cheyadaniki vadatamu
// deeniki struct  vadatamu

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *list[26];    // endhuku 26 anteh 26 characters untayi kabatti
    bool flag = false; // endhuku anteh endhuku danni nunchi emi words form avvaledu ani anukuntamu
    // echchina character unda leda ani testing
    bool contain_key(char ch)
    {
        return list[ch - 'a'] != NULL;
    }
    void put_char(char ch, node *temp)
    {
        list[ch - 'a'] = temp;
    }
    node *get_reference_node(char ch)
    {
        return list[ch - 'a'];
    }
    bool is_end()
    {
        return flag;
    }
    void set_end()
    {
        flag = true;
    }

}
 class trie
{
    private:
    node *root;

public:
    trie()
    {
         root = new node();
    }
    // kottaga emaina word vaste insert chestamu prati character ni
    void insert(string word)
    {
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contain_key(word[i]))
            {
                point_root->put_char(word[i], new node());
            }
            // move to the reference trie
            point_root = point_root->get_reference_node(word[i]);
        }
        // setting last one to the null
        point_root->set_end();
    }

    // search word undha ledha ani testing.ekkada mottam word already previous gaa exit avutunda ledha ani checking 
    bool search(string word)
    {
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contain_key(word[i]))
            {
                return false;
            }
            // next reference node ki nuvvu travel avvali
            point_root = point_root->get_reference_node(word[i]);
        }
        return point_root->is_end();
    }
    //echchina word tho start avutunda ledha ani checking
    bool starts_with(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contain_key(word[i]))
            {
                return false;
            }
            // next reference node ki nuvvu travel avvali
            point_root = point_root->get_reference_node(word[i]);
        }
        return true;
    }

} int main()
{

    return 0;
}