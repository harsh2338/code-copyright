#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int solve(int n,int k){
	if(n==1)return dp[n][k]=k;
	if(k==1 || k==0)return dp[n][k]=k;
    if(dp[n][k]!=-1)return dp[n][k];
	int ans=INT_MAX;
	for(int i=1;i<=k;i++){
		ans=min(ans,1+max(solve(n-1,i-1),solve(n,k-i)));
    }
    cout<<n<<" "<<k<<" "<<ans<<"\n";
    return dp[n][k]=ans;
}
int solveBottomUp(int n,int k){
    int res;
    for(int i=1;i<=k;i++)dp[1][i]=i;
    for(int i=1;i<=n;i++)dp[i][1]=1;
    for(int i=2;i<=n;i++){
        int ans=INT_MAX;
        for(int j=2;j<=k;j++){
            int temp=INT_MAX;
            for(int x=1;x<=j;x++){
                res = 1 + max( 
                              dp[i - 1][x - 1], 
                              dp[i][j - x]); 
                if (res < dp[i][j]) 
                    dp[i][j] = res;            }
        }
    }
    return dp[n][k];
}
int main(){
	int n=2,k=100;
    vector<vector<int>>x(n+1,vector<int>(k+1,0));
    dp=x;
	cout<<solveBottomUp(n,k);
}
