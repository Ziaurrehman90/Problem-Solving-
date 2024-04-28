class Solution
{
public:
    // USING BFS ONLY

    bool bip(int V, vector<vector<int>> &adj, vector<int> &color, int start)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto cur_node : adj[node])
            {
                // dekhunga k agr mere connected node color nhi h tou usko opppsitte color kr dunga
                if (color[cur_node] == -1)
                {
                    color[cur_node] = !color[node];
                    q.push(cur_node);
                }
                // agr meri adjacent node ka same color hota h parent node s then wo m color nhi kr paunga tou simply falsr return kr dunga
                else if (color[cur_node] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        // lets first create an adjacency list
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (bip(V, graph, color, i) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};