#include<stack>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
stack<char>st;
unordered_map<char,bool>vis;
unordered_map<char,vector<char>>adj;
string dict[]={ "baa", "abcd", "abca", "cab", "cad" };
void topoUtil(char u){
    vis[u]=true;
    for(char v:adj[u]){
        if(vis.find(v)==vis.end())
            topoUtil(v);
    }
    st.push(u);
}
void topoSort(int k){
    for(char c='a';c<'a'+k;c++){
        if(vis.find(c)==vis.end())
        topoUtil(c);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
void makeGraph(){

    for(int i=1;i<5;i++){
        string w1=dict[i-1],w2=dict[i];
        int j=0;
        while(j<min(w1.length(),w2.length())&& w1[j]==w2[j])j++;
        cout<<w1<<" "<<w2<<" "<<w1[j]<<" "<<w2[j]<<"\n";
        adj[w1[j]].push_back(w2[j]);
    }

}
int main(){
    makeGraph();
    topoSort(4);
    cout<<"\n";
    for(auto c=adj.begin();c!=adj.end();c++){
        cout<<c->first<<":";
        for(char i:adj[c->first])cout<<i;
        cout<<"\n";
    }

}