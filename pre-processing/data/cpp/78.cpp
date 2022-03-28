// C++ program to find number of ways to get sum 'x' with 'n' 
// dice where every dice has 'm' faces 
#define M %1000000007

#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 
int findWays(int d, int f, int target) {
        vector<vector<int>> dp(f+1,vector<int>(target+1));
        for(int i=1;i<=d;i++)dp[1][i]=1;
        for(int i=2;i<=target;i++){
            for(int j=1;j<=f;j++){
                dp[i][j]=(dp[i-1][j-1] M +dp[i][j-1] M) M;
                if(j-d>0){
                    dp[i][j]=(dp[i][j] M - dp[i-1][j-d-1] M )M;
                }
            }
        }
        return dp[f][target];
    }
// Driver program to test above functions 
int main() 
{ 
	cout << findWays(4, 2, 1) << endl<<endl; 
	cout << findWays(2, 2, 3) <<endl<<endl; 
	cout << findWays(6, 3, 8) << endl<<endl; 
	cout << findWays(4, 2, 5) << endl<<endl; 
	cout << findWays(4, 3, 5) << endl<<endl;  

	return 0; 
} 


