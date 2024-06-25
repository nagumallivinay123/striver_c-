#include <bits/stdc++.h>
using namespace std;
//c ki mariyu c++ struct lo difference enti anteh c++ struct lo nuvvu functions avi insert cheyachchu 

//doubt vaste striver codestudio chusuko 
//andulo example teesukoni chuste ardamavutundi 
struct node
{
    node *list[26];      // endhuku 26 characters anevi untayi
    int count_words = 0; // ekkada counting of words adigarau kabatti danibatti
                         // node structure ni marchukunnavu
    int count_upto_prefix_words = 0;
    //ekkada main thought process ravalisindi ekkade count_words and count_upto_prefix_words
     

    
    bool contains_key(char ch) { return (list[ch - 'a'] != NULL); }
    void put_key(char ch, node *some) { list[ch - 'a'] = some; }
    node *get_next_reference_key(char ch) { return list[ch - 'a']; }
    void increase_count_word() { count_words++; }
    void increase_prefix_word() { count_upto_prefix_words++; }
    void delete_word() { count_words--; }
    void delete_prefix() { count_upto_prefix_words--; }
    int get_words() { return count_words; }
    int get_prefix_words() { return count_upto_prefix_words; }
};
class Trie
{
private:
    node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new node();
    }

    void insert(string &word)
    {
        // Write your code here.
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contains_key(word[i]))
            {
                point_root->put_key(word[i], new node());
            }
            // move to the reference trie
            point_root = point_root->get_next_reference_key(word[i]);
            point_root->increase_prefix_word();
        }
        point_root->increase_count_word();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contains_key(word[i]))
            {
                return 0;
            }
            else
            {
                point_root = point_root->get_next_reference_key(word[i]);
            }
            // move to the reference trie
        }
        return point_root->get_words();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contains_key(word[i]))
            {
                return 0;
            }
            else
            {
                point_root = point_root->get_next_reference_key(word[i]);
            }
            // move to the reference trie
        }
        return point_root->get_prefix_words();
    }

    void erase(string &word)
    {
        // Write your code here.
        node *point_root = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!point_root->contains_key(word[i]))
            {
                break;
            }

            point_root = point_root->get_next_reference_key(word[i]);
            point_root->delete_prefix();
        }
        point_root->delete_word();
    }
};
int main()
{
    return 0;
}