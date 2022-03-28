#include<bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V;
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);
    void addEdge(int u, int v, int w); 
    void shortestPath(int s); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
void Graph::shortestPath(int src){
    set<pair<int,int>>heap;
    vector<int>dis(V,INT_MAX);
    dis[src]=0;
    heap.insert({0,src});
    while(!heap.empty()){
        pair<int,int>p=*heap.begin();
        heap.erase(heap.begin());
        int u=p.second;
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            int d=it->first;
            int v=it->second;
            if(dis[v]>dis[u]+d){
                if(dis[v]!=INT_MAX)
                    heap.erase(heap.find({dis[v], v}));
                heap.insert({dis[u]+d,v});
                dis[v]=dis[u]+d;
            }
        }
    }
    for(int i:dis)cout<<i<<" ";
}
int main() 
{ 
    int V = 9; 
    Graph g(V); 
  
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0; 
} 