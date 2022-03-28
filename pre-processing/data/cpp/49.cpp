#include<bits/stdc++.h>
using namespace std;
int main(){
    set<pair<int,int>,greater<>>st;
    int ans=0;
    int A[]={5, 0, 1, 3, 2, 4, 1, 0, 5};
    int c=4,n=9;
    unordered_map<int,int>mp;
    for(int i=0;i<n && i<c;i++){
        ans++;
        mp[A[i]]=i;
        st.insert({i,A[i]});
    }
    for(int i=c;i<n;i++){
        auto mapIndex=mp.find(A[i]);
        if(mapIndex==mp.end()){
            if(st.size()>=c){
                auto setIndex=st.end();
                setIndex--;
                pair<int,int> ele=*setIndex;
                mp.erase(ele.second);
                st.erase(setIndex);
            }
            mp[A[i]]=i;
            st.insert({i,A[i]});
            ans++;
        }
        else{
            auto setIndex=st.find({mp[A[i]],A[i]});
            st.erase(setIndex);
            st.insert({i,A[i]});
            mp[A[i]]=i;
        }
    }
    cout<<ans;

}