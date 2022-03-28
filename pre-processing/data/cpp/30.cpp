#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int c;
int mindiff(vector<int>A,int i,int sum,int totsum){
    c++;
    if(i==A.size())return abs((totsum-sum)-sum);
    string c1=to_string(i+1)+":"+to_string(sum);
    string c2=to_string(i+1)+":"+to_string(sum+A[i]);
    if(mp.find(c1)==mp.end()){
        mp[c1]=mindiff(A,i+1,sum,totsum);
    }
    if(mp.find(c2)==mp.end()){
        mp[c2]=mindiff(A,i+1,sum+A[i],totsum);
    }
    return min(mp[c1],mp[c2]);
}
int main(){
    mp.clear();
    c=0;
    vector<int>A={3, 1, 4, 2, 2, 1};
    int tot=0;
    for(int i:A)tot+=i;
    cout<<mindiff(A,0,0,tot)<<"\n"<<mp.size();
    cout<<"\n\n"<<c;
    // for(auto it =mp.begin();it!=mp.end();it++)cout<<it->first<<" "<<it->second<<"\n";
}