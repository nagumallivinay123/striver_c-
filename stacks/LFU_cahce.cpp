#include<bits/stdc++.h>
using namespace std;
//LRU ki double linkedlist maintain chestamu deeniki kuda alane avvali 
//striver LFU implementation -> https://www.youtube.com/watch?v=mzqHlAW7jeE
//striver L
struct Node{
 int key;
 int  count;
 int val;
 Node *prev;
 Node *next;
 Node(int keys,int vals){
    key=keys ;
    val=vals;
    count=1;
    prev=NULL;
    next=NULL;
 }


};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;

    }
    void addFront(Node *add){
        Node *nexts=head->next;
        add->prev=head;
        add->next=nexts;
        nexts->prev=add;
        head->nexts=add;
        size++;
    }
    void removeNode(Node *del){
        Node *delprev=del->prev;
        Node *delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        del->prev=NULL;
        del->next=NULL;
        size--;
    }

};


class LFU{
    map<int,Node*>keyNode;
    map<int,List*>freqListMap;
    int max_size_cache;
    int minFreq;
    int curSize;
    public:
    LFU(int cacheSize){
        max_size_cache=max_size_cache;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->count]->removeNode(node);
        if(node->count==minFreq && freqListMap[node->count]->size==0){
            minFreq++;
        }
        List *nextHigherFreqList=new List();
        if(freqListMap[node->count+1]!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->count+1];
        }
        node->count+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->count]=nextHigherFreqList;
        keyNode[node->key]=node;
    }

    int get(int key){
        if(keyNode.find(key)!=keyNode.end){
            Node *node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    void put(int key,int val){
        if(max_size_cache==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *node=keyNode[key];
            node->val=val;
            updateFreqListMap(node);


        }
        else
        {
           if(curSize==max_size_cache){
                List *list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
           }
           curSize++;
           minFreq=1;
           List *listfreq=new List();
           if(freqListMap.find(minFreq)!=freqListMap.end()){
            listfreq=freqListMap[minFreq];
           }
           Node *node=new Node(key,val);
           listfreq->addNode(node);
           keyNode[key]=node;
           freqListMap[minFreq]=listfreq;
        }
    }

};



int main(){
return 0;
}