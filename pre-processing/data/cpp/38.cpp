#include<bits/stdc++.h>
using namespace std;
string lps(string s){
    int n=s.length();
    map<string,bool>mp;
    string ans="";
    for(int i=0;i<n;i++){
        for(int j=i;j<n && abs(i-j)!=n;j++){

            string temp=s.substr(i,j);
            if(mp.find(temp)==mp.end())
                mp[temp]=true;
            else
                if(ans.length()<temp.length())
                    ans=temp;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)cout<<it->first<<"\n";
    return ans;
}
int lpsEfficient(string s){
    int n=s.length();
    int len=0;
    vector<int>lps(n,0);
    int i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        } 
    }
    for(int i:lps)cout<<i<<" ";
    return len;

}
int main(){
    string s="aabcdaabc";
    cout<<lpsEfficient(s);
}
