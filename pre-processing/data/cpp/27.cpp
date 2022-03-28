#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>A,vector<int>B,int sA,int eA,int sB,int eB,int k){
    if(sA==eA)return  B[k];
    if(sB==eB)return A[k];
    int m1=(sA+eA)/2,m2=(sB+eB)/2;
    if(m1+m2<k){
        if(A[m1]>B[m2]){
            return solve(A,B,m1+1,eA,sB,eB,k-m1-1);
        }
        else{
            return solve(A,B,sA,eA,m2+1,eB,k-m2-1);
        }
    }
    else{
        if(A[m1]>B[m2]){
            return solve(A,B,sA,m1,sB,eB,k);
        }
        else{
            return solve(A,B,sA,eA,sB,m2,k);
        }
    }

    return 0;
}
int main(){

    vector<int>A={ 2, 3, 6, 7, 9 },B={ 1, 4, 8, 10 };
    cout<<solve(A,B,0,A.size()-1,0,B.size()-1,5);
}