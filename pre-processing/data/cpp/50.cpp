#include<bits/stdc++.h>
using namespace std;
int N=9;
vector<vector< int>> grid = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
// Driver Code 
bool isValid(int r,int c,int val){
    for(int i=0;i<9;i++){
        if(grid[r][i]==val ||grid[i][c]==val)return false;
    }
    int checkr,checkc;
    if(r>=6)checkr=6;
    else if(r>=3)checkr=3;
    else checkr=0;
    if(c>=6)checkc=6;
    else if(c>=3)checkc=3;
    else checkc=0;
    for(int i=checkr;i<checkr+3;i++){
        for(int j=checkc;j<checkc+3;j++)
            if(grid[i][j]==val)return false;
    }
    return true;
    
}
pair<int,int> getNext(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0)return {i,j};
        }
    }
    return {10,0};
}
bool SolveSudoku(int r,int c){
    if(r>=9)return true;
    if(grid[r][c]!=0) return true;
    for(int i=1;i<=9;i++){
        if(isValid(r,c,i)){
            grid[r][c]=i;
            pair<int,int> p=getNext();
            if(!SolveSudoku(p.first,p.second)){
                grid[r][c]=0;
            }
        }
    }
    if(grid[r][c]==0)return false;
    return true;
}
void printGrid() 
{ 
    for (int row = 0; row < 9; row++) { 
        for (int col = 0; col < 9; col++) 
            cout << grid[row][col] << " "; 
        cout << endl; 
    } 
} 
int main() 
{ 
    pair<int,int>p=getNext();
    if (SolveSudoku(p.first,p.second) == true) 
        printGrid(); 
    else
        cout << "No solution exists"; 
  
    return 0; 
} 