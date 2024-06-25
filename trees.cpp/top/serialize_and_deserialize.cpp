//ekkada level order serialize chestam 
//binary tree structure ni mottam string kinda marchali -serialize antamu 
//string ni mottam malli binary tree kinda marchali anteh koddiga kastam
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
string serialize(Node *root){
    string outputs="";
    if(root==NULL){
        return outputs;
    }
    queue<Node *>store;
    store.push(root);
    while(!store.empty()){
        Node *temp=store.front();
        store.pop();
        if(temp==NULL){
            outputs.append("#,");
        }
        else{
            outputs.append(to_string(temp->data)+",");
        }
        if(temp!=NULL){
            store.push(temp->left);
            store.push(temp->right);
        }
    }
    return outputs;
}
Node *deserialize(string traverse)
{
    if(traverse.size()==0)
    return NULL;

    stringstream s(traverse);
    string str;
    getline(s,str,",");
    Node *root=new Node(stoi(str));
    queue<Node *>store;
    store.push(root);
    while(!store.empty())
    {
        Node *temp=store.front();
        store.pop();
        getline(s,str,",");
        if(str=="#"){
            temp->left=NULL;
        }
        else{
           temp->left=new Node(stoi(str));
           store.push(temp->left);
        }
        getline(s,str,",");
        if(str=="#"){
            temp->right=NULL;
        }
        else{
            temp->right=new Node(stoi(str));
            store.push(temp->right);
        }

    }
    return root;

}
int main(){
//eppudaina string spliting doubt vachchindi anteh edokasari dry run cheyi
// string s="v,i,n,a,y";
// stringstream v(s);
// string str;
// getline(v,str,',');
// cout<<str<<"\n";
// getline(v,str,',');
// cout<<str<<"\n";
return 0;}