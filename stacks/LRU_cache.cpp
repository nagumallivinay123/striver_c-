#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    int key;
    Node *prev;
    Node *next;
    Node(int keys, int vals)
    {
        key = keys;
        val = vals;
        prev = NULL;
        next = NULL;
    }
};
class LRU
{
    int cap = 0;
    unordered_map<int, Node *> mp;

    Node *start = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

public:
    LRU(int capacity)
    {
        cap = capacity;
        addNode(tail);
    }
    void addNode(Node *add)
    {
        Node *some = start->next;
        add->next = some;
        add->prev = start;
        if (some != NULL)
        {
            some->prev = add;
        }
        start->next = add;
    }
    void deleteNode(Node *del)
    {
        Node *previous = del->prev;
        Node *nexts = del->next;
        nexts->prev = previous;
        previous->next = nexts;
        del->next = NULL;
        del->prev = NULL;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *some = mp[key];
        // cout<<some->key<<"\n";
        int val = some->val;
        deleteNode(some);
        addNode(some);
        return val;
    }
    void put(int key, int val)
    {
        if (mp.find(key) == mp.end())
        {
            if (cap == 0)
            {
                int keys = tail->prev->key;
                mp.erase(keys);
                Node *del = tail->prev;
                deleteNode(del);
                delete del;
            }
            else
            {

                cap--;
            }
            Node *some = new Node(key, val);
            addNode(some);
            mp[key] = some;
        }
        else
        {
            Node *some = mp[key];
            deleteNode(some);
            addNode(some);
            some->val = val;
        }
    }
};
int main()
{
    LRU some(2);
    some.put(2,1);
    some.put(1,1);
    cout << some.get(2) << "\n";
    some.put(4,1);
   
    cout << some.get(1) << "\n";
    cout << some.get(2) << "\n";


    return 0;
}