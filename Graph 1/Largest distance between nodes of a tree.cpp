void dfs(int node,vector<vector<int>> &graph,vector<bool> &vis,int &ans,int &maxi,int &k){
        vis[node]=1;
       
        ans++;
        if(maxi<ans){
            maxi=ans;
            k=node;
        }
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,graph,vis,ans,maxi,k);
            }
        }
        ans--;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>adjList(n+1);
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1){
            adjList[i].push_back(A[i]);
            adjList[A[i]].push_back(i);
        }
        
    }
    int zia=0;
    int maxi=0;
    int k=0;
    vector<bool>visited(n,false);
     dfs(0,adjList,visited,zia,maxi,k);
     zia=0,maxi=0;
       
     vector<bool> visited1(n,false);
        dfs(k,adjList,visited1,zia,maxi,k);
        return maxi-1;
             
    
}
