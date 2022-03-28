#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
const double pi = acos(-1);
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=((ans%m)*(a%m))%m;
a=((a%m)*(a%m))%m;b>>=1;}return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

unordered_map<int,bool>visited;
unordered_map<int,vector<int>>adj;
stack<int>st;
vector<int>arr;
void topoSortUtil(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            topoSortUtil(v);
        }
    }
    st.push(u);
}
void topoSort(){
    for(int u : arr){
        if(!visited[u]){
            topoSortUtil(u);
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    visited.clear();
    adj.clear();
    for(int i=0;i<6;i++){
        arr.pb(i);
        visited[i]=false;
    }
    adj[5].pb(2);
    adj[5].pb(0);
    adj[4].pb(0);
    adj[4].pb(1);
    adj[2].pb(3);
    adj[3].pb(1);
    topoSort();
}