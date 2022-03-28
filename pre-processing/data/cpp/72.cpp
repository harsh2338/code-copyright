class U{
    public: 
    unordered_map<int,bool>row,col;
    int ele;
    U(int r, int c){
        row[r]=true;
        col[c]=true;
        ele=1;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>> A) {
        vector<U*>uset;
        int n=A.size();
        for(int i=0;i<n;i++){
            bool chk=false;
            for(U* j:uset){
                if(j->row.find(A[i][0])!=j->row.end() || j->col.find(A[i][1])!=j->col.end()){
                    j->row[A[i][0]]=j->col[A[i][1]]=true;
                    j->ele++;
                    chk=true;
                    break;
                
                }
            }
            if(!chk)uset.push_back(new U(A[i][0],A[i][1]));
        }
        int ans=0;
        for(U* i:uset){
            ans=max(ans,-1+i->ele);
        }
        return ans;
        
    }
};
int main(){
    Solution *sol = new Solution();
    sol->removeStones({{0,1},{1,0},{1,1}});
}

