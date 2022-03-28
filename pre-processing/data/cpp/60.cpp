#include<bits/stdc++.h>
using namespace std;
int change[]={1,2,3};
unordered_map<int,int>dp;
int ans=0;
int solve(int amount){
	if(amount==0){
	    return 1;
    }
    for(int i:change){
        if(amount-i>=0){
            if(dp.find(amount-i)==dp.end()){
                dp[amount-i]=solve(amount-i);
            }
            dp[amount]+=dp[amount-i];	
        }
    }
    return dp[amount];	
}

int main(){
    cout<<solve(4);
    for(auto it=dp.begin();it!=dp.end();it++){
        cout<<it->first<<":"<<it->second<<"\n";
    }
}
