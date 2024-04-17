class Solution {
public:
// bfs function 
void bfs(int i,int j,vector<vector<int>>&visited,vector<vector<char>>&grid){
    queue<pair<int,int>>q;
    int n=grid.size();
    int m=grid[0].size();
    visited[i][j]=1;
    q.push({i,j});
    while(!q.empty()){
        int row=q.front().first;
        int column=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrows=row+delrow;
                int ncols=column+delcol;
                if(delrow!=0 && delcol!=0){
                    continue;
                }
                if(nrows>=0 && nrows<n && ncols>=0 && ncols<m && grid[nrows][ncols]=='1' && !visited[nrows][ncols]){
                    visited[nrows][ncols]=1;
                    q.push({nrows,ncols});
                }
            }
        }

    }
}
    int numIslands(vector<vector<char>>& grid) {
        // marking number of rows and columns 
        int n=grid.size();
        int m=grid[0].size();
        // making 2d array of visited 
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;

        
    }
};