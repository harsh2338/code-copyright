class Solution {
public:
    int orangesRotting(vector<vector<int>>& A) {
        queue<pair<int,int>>q;
        int n=A.size();
        int m=A[0].size();
        int fresh=0;
        int ans=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==2)q.push({i,j});
                else if(A[i][j]==1)fresh++;
            }
        }
        while(!q.empty()){
            int s=q.size();
            while(s--)}{
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(i+1<n && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    fresh--;
                }
                if(j+1<m && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    fresh--;
                }
            }
            if(q.empty())break;
            else ans++;
        
        }
        
    }
};