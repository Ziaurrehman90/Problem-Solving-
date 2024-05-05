void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;
    for (auto neigh : adj[node])
    {
        if (visited[neigh] == false)
        {
            dfs(neigh, visited, adj, st);
        }
    }

    st.push(node);
}

void revDFS(int node, vector<bool> &visited, vector<vector<int>> &transpose)
{
    visited[node] = true;

    for (auto neigh : transpose[node])
    {
        if (!visited[neigh])
            revDFS(neigh, visited, transpose);
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{

    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    vector<vector<int>> transpose(V);

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        for (auto neigh : adj[i])
        {
            transpose[neigh].push_back(i);
        }
    }
    int count = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (visited[top] == false)
        {
            count++;
            revDFS(top, visited, transpose);
        }
    }

    return count;
}