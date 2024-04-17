class Solution {
public:
void dfs(int row,int column,vector<vector<char>>&board){
    int n=board.size();
    int m=board[0].size();
    if(row<0 || row>=n || column <0 || column>=m || board[row][column]!='O'){
        return;
    }
    board[row][column]='#';
    dfs(row-1,column,board);
    dfs(row+1,column,board);
    dfs(row,column+1,board);
    dfs(row,column-1,board);

}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        // apply dfs only boundry rows and columns 
        // for 1st and last row condtion 
        for(int i=0;i<m;i++){
            // for first row 
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
            // for last row situation 
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board);
            }
        }

        // for first and last column 
         for(int j=0;j<n;j++){
            //  for first column 
            if(board[j][0]=='O'){
                dfs(j,0,board);
            }
            // for last column 
            if(board[j][m-1]=='O'){
                dfs(j,m-1,board);
            }
         }
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                  if(board[i][j]=='O'){
                     board[i][j]='X';
                 }
                 if(board[i][j]=='#'){
                     board[i][j]='O';
                 }
                
             }
         }


        
    }
};