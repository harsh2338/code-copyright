void krushkal(){
    DisjointSet ds;
    for(Node* node :Nodes){
        ds.makeset(node);
    }
    sort(edges by weight)
    for(Edge e in Edges){
        u=e.first;
        v=e.second;
        if(ds.findSet(u)!=ds.findSet(v)){
            res.push_back(e);
            ds.union(u,v)
        }
    }
}