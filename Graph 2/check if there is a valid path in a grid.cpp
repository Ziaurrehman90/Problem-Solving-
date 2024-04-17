// class Solution {
// public:
// bool dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
//     int n=grid.size();
//     int m=grid[0].size();
//     if(row<0 || row>=n || col<0 || col>=m || visited[row][col]==1){
//         return false;
//     }
//     if(row==n-1 && col==m-1){
//         return true;
//     }
//     visited[row][col]=1;
//     // case 1 when street==1
//     bool a,b,c,d,e,f,g,h,i,j,k,l;
//     a=b=c=d=e=f=g=h=i=j=k=l=false;
//     if(grid[row][col]==1){
//         if(col-1>=0 && (grid[row][col-1]==1 || grid[row][col-1]==4 || grid[row][col-1]==6) ){
//             a=dfs(row,col-1,grid,visited);
//         }
//         if(col+1<m && (grid[row][col+1]==1 || grid[row][col+1]==3 || grid[row][col+1]==5)){
//             b=dfs(row,col+1,grid,visited);
//         }
//     }

//     // jab meri street 2 h 
//     if(grid[row][col]==2){
//         if(row+1<n && (grid[row+1][col]==2 || grid[row+1][col]==5 || grid[row=1][col]==6)){
//             c=dfs(row+1,col,grid,visited);
//         }
//         if(row-1>=0 && (grid[row-1][col]==2 || grid[row-1][col]==3 || grid[row-1][col]==4)){
//             d=dfs(row-1,col,grid,visited);
//         }
//     }

//     // streee 3 ki baari h ab 
//     if(grid[row][col]==3){
//         if(col-1>=0 && (grid[row][col-1]==1 || grid[row][col-1]==6 || grid[row][col-1]==4 )){
//             e=dfs(row,col-1,grid,visited);
//         }
//         if(row+1<n && (grid[row+1][col]==6 || grid[row+1][col]==5 ||grid[row+1][col]==2 ))
//     }

//     if(grid[row][col]==4){
//             if(col+1<m && (grid[row][col+1]==1 || grid[row][col+1]==3 || grid[row][col+1]==5))
//                 g=helper(row,col+1,grid,visited);
//             if(i+1<m && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
//                 h=helper(grid,i+1,j,m,n,visited);
//         }
//         if(grid[i][j]==5){
//             if(i-1>=0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
//                 o=helper(grid,i-1,j,m,n,visited);
//             if(j-1>=0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
//                 p=helper(grid,i,j-1,m,n,visited);
//         }
//         if(grid[i][j]==6){
//             if(i-1>=0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
//                 k=helper(grid,i-1,j,m,n,visited);
//             if(j+1<n && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
//                 l=helper(grid,i,j+1,m,n,visited);
//         }



// }
//     bool hasValidPath(vector<vector<int>>& grid) {
//           int n=grid.size();
//           int m=grid[0].size();
//           vector<vector<int>>visited(n,vector<int>(m,0));
//           return dfs(row,col,0,0,grid,visited);

        
//     }
// };

class Solution {
public:
    
    bool helper(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j]==true)
            return false;
        if(i==m-1 && j==n-1)
            return true;
        visited[i][j]=true;
        bool a=false,b=false,c=false,d=false,e=false,f=false,g=false,h=false,o=false,p=false,k=false,l=false;
        if(grid[i][j]==1){
            if(j-1>=0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                a=helper(grid,i,j-1,m,n,visited);
            if(j+1<n && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                b=helper(grid,i,j+1,m,n,visited);
        }
        if(grid[i][j]==2){
            if(i-1>=0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
                c=helper(grid,i-1,j,m,n,visited);
            if(i+1<m && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                d=helper(grid,i+1,j,m,n,visited);
        }
        if(grid[i][j]==3){
            if(j-1>=0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                e=helper(grid,i,j-1,m,n,visited);
            if(i+1<m && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                f=helper(grid,i+1,j,m,n,visited);
        }
        if(grid[i][j]==4){
            if(j+1<n && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                g=helper(grid,i,j+1,m,n,visited);
            if(i+1<m && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6))
                h=helper(grid,i+1,j,m,n,visited);
        }
        if(grid[i][j]==5){
            if(i-1>=0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
                o=helper(grid,i-1,j,m,n,visited);
            if(j-1>=0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6))
                p=helper(grid,i,j-1,m,n,visited);
        }
        if(grid[i][j]==6){
            if(i-1>=0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4))
                k=helper(grid,i-1,j,m,n,visited);
            if(j+1<n && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5))
                l=helper(grid,i,j+1,m,n,visited);
        }
        return (a || b || c || d || e || f || g || h || o || p || k || l);
        
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return helper(grid,0,0,m,n,visited);
    }
};