#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int solve(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 3;
    if(n==4)return 4;
    int ans=INT_MIN;
    for(int i=1;i<=n/2;i++){
        if(mp.find(i)==mp.end())mp[i]=solve(i);
        if(mp.find(n-i)==mp.end())mp[n-i]=solve(n-i);
        
        ans=max(ans,mp[i]*mp[n-i]);
    }
    return ans;
}
int solve3(int n){
    int ans=1;
    while(n>4){
        n-=3;
        ans*=3;
    }
    return n*ans;
}
int main(){
    int n=10;
    mp.clear();
    cout<<solve3(n);

}