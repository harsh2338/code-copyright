#include<bits/stdc++.h>
using namespace std;
#define ll long long


    int atMostNGivenDigitSet(vector<string>& A, int n) {
        int dig=0;
        int temp=n;
        while(temp){
            dig++;
            temp/=10;
        }
        
        int ans=0;
        int si=A.size();
        for(int i=1;i<dig;i++){
            ans+=pow(si,i);
        }
        string ns=to_string(n);
        if(ns.length()==1){
            int i=0;
            while(i<si && A[i][0]<=ns[0])i++;
            return i;
        }
        int i=si-1,j=0;
            while(i>=0 && A[i][0]>ns[j]){
                i--;
            }
            if(i<0)
                return ans;
            if(A[i][0]==ns[j]){
                
                if(ns.length()==1){
                    ans+=1;
                }
                else{
                    string s=ns.substr(j+1);
                    ans+=atMostNGivenDigitSet(A,stoi(s));
                }
            }
            ans+=i*pow(si,dig-1);

            
        return ans;
        
    }
int main(){
    // vector<vector<string>> A =
    //     {{"David", "David0@m.co", "David1@m.co"}, {"David", "David3@m.co", "David4@m.co"}, {"David", "David4@m.co", "David5@m.co"}, {"David", "David2@m.co", "David3@m.co"}, {"David", "David1@m.co", "David2@m.co"}};
    // Solution().accountsMerge(A);
    vector<string> A = { "1","3","5","7"};
    atMostNGivenDigitSet(A, 135);
}