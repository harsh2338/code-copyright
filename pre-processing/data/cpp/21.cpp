#include<bits/stdc++.h>
using namespace std;

int minSwaps(){
    vector<int>A={5,2,7,9,6,3,4,1,0,8};
    int n=A.size(),ans=0;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int c=1;
            vis[i]=true;
            int j=A[i];
            cout<<A[i]<<" ";
            while(!vis[j]){
                cout<<A[j]<<" ";
                vis[j]=true;
                j=A[j];
                c++;
            }
            ans+=c-1;
            cout<<"\n";
        }        
    }
    cout<<ans;
}