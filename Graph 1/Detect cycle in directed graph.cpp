class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int source, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[])
    {
        // sabse phle kya krenge :
        // us node ko viisted mark kr leta hn and uske path visited bhi mark kr leta hn
        visited[source] = 1;
        pathVisited[source] = 1;
        for (auto &child : adj[source])
        {
            if (!visited[child])
            {

                if (dfs(child, visited, pathVisited, adj) == true)
                {
                    return true;
                }
            }
            else if (pathVisited[child])
            {
                return true;
            }
        }
        // yahah pr backtraking ka kaam krunga jab wapas lautunga tou wo node uske path visited s bhi nikal dunga
        pathVisited[source] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, pathVisited, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};