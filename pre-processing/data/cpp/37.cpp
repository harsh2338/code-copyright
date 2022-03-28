#include<bits/stdc++.h>
using namespace std;
vector<int>A={2,5,7,1,4,3,1,3};
vector<vector<int>>dp;
int solve(int k,int n){
    if(n==1|| k==0)return dp[n][k]=0;
    if(dp[n][k]!=-1)return dp[n][k];
    int ans=0;
    for(int i=1;i<n;i++){
            ans=max(solve(k,i-1),A[n]-A[i]+solve(k-1,i));
     }
    return dp[n][k]=ans;

}
int main(){
    int n=A.size();
    int k=n;
    dp=vector<vector<int>>(k+1,vector<int>(n,-1));
    cout<<solve(k,n)<<"\n";
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++)
        cout<<dp[i][j]<<"\t";
        cout<<"\n";
    }
}