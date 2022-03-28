#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* par;
    int rank;
    Node(int val){
        this->val=val;
        this->par=this;
        this->rank=0;
    }
};
class DisjointSet{

    public:
    Node* makeSet(int val){
        return new Node(val);
    }
    Node* findSet(Node* u){
        if(u->par==u)
            return u;
        u->par=findSet(u->par);
        return u->par;
    }

    void join(Node* u1,Node* u2){
        Node* p1=findSet(u1);
        Node* p2=findSet(u2);
        if(p1==p2)
            return;
        if(p1->rank>p2->rank)
            p1->par=p2;
        else
            p2->par=p1;
        if(p1==p2)
            p1->rank++;       
        
    }

};
int main(){
    DisjointSet ds=DisjointSet();
    Node *a=ds.makeSet(1);
    Node *b=ds.makeSet(2);
    ds.join(a,b);
    Node *c=ds.makeSet(3);
    ds.join(b,c);
    cout<<a->par->val;
    cout<<b->par->val;
    cout<<c->par->val;

    
}

