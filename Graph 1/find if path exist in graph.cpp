class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // lets create a first adjacency list 
        vector<vector<int>>adjList(n);
        for(auto &it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination){
                return true;
            }
            for(auto &it:adjList[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
            return false;

        

    }
};