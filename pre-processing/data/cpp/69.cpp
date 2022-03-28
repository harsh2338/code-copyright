#include <bits/stdc++.h> 
using namespace std; 
  
// Function to check no of  subarray with sum 
// exists when negative elements are also present 
void subArraySum(int arr[], int n, int sum) 
{ 
    unordered_map<int,int>mp;
    int cur=arr[0];
    mp[0]=true;
    mp[cur]=1;
    int ans=0;
    if(cur==sum)ans++;
    for(int i=1;i<n;i++){
        cur+=arr[i];
        if(mp.find(cur-sum)!=mp.end())ans+=mp[cur-sum];
        mp[cur]++;
    }
    cout<<ans;
} 
// Driver Code 
int main() 
{ 
    int arr[] = {9, 4, 20, 3, 10, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    int sum = 33; 
  
    subArraySum(arr, n, sum); 
  
    return 0; 
} 