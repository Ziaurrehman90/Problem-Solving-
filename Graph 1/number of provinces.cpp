class Solution {
public:
void dfs(int node,vector<int>adjList[],vector<int>&visited){
    visited[node]=1;
    for(auto it:adjList[node]){
        if(!visited[it]){
            dfs(it,adjList,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        // conversion of adjacency matrix to adjacency list  
        int n=isConnected.size();
        vector<int>adjList[n];
        vector<int>visited(n);
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,adjList,visited);
            }
        }
        return count;

        
    }
};