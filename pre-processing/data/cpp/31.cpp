#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>A={3,4,7,2,-3,1,4,2};
    int k=7;
    int n=A.size();
    int ans=0;
    unordered_map<int,bool>mp;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        mp[sum]=true;
        if(sum==k || mp[sum-k]!=NULL)
            ans++;
    }
    cout<<ans;
}