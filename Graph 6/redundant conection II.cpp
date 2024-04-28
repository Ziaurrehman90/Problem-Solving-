class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    // constructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    // lets make a function of find parents
    int findUpar(int node)
    {
        // base case
        if (node == parent[node])
        {
            return node;
        }
        // recursive case
        return parent[node] = findUpar(parent[node]);
    }
    bool connected(int node1, int node2)
    {

        int parent1 = findUpar(node1);
        int parent2 = findUpar(node2);

        if (parent1 == parent2)
            return true;
        else
            return false;
    }
    // here's the function of union
    void UniounByRank(int u, int v)
    {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        // if both have same parents then there is no need of the coonection
        if (up_u == up_v)
        {
            return;
        }
        // now let's check for the rank
        // case1:
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        // second case
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        // last case
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        // first let's count the indegree of each and every node
        int n = edges.size();
        vector<int> inDegree(n + 1);
        int deg = -1;
        for (int i = 0; i <= n; i++)
        {
            inDegree[i] = 0;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> temp = edges[i];
            int u = temp[0];
            int v = temp[1];
            inDegree[v]++;
            if (inDegree[v] == 2)
            {
                deg = v;
            }
        }
        // jab cycle exist kr rhi h tab
        if (deg == -1)
        {
            DisjointSet ds(n);
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                if (ds.findUpar(u) == ds.findUpar(v))
                {
                    return {u, v};
                }
                ds.UniounByRank(u, v);
            }
        }
        // ab cycle exist nhi kr rhi mujhe wo edge nikalni h jo faltu ki added h
        int deg1 = -1;
        int deg2 = -1;
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (inDegree[v] == 2)
            {
                if (deg1 == -1)
                {
                    deg1 = i;
                }
                else
                {
                    deg2 = i;
                }
            }
        }
        DisjointSet ds(n);
        bool stillcycle = false;
        for (int i = 0; i < n; i++)
        {

            if (i == deg2)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if (ds.connected(u, v))
            {
                stillcycle = true;
            }
            else
            {
                ds.UniounByRank(u, v);
            }
        }

        if (!stillcycle)
        {
            return {edges[deg2][0], edges[deg2][1]};
        }

        return {edges[deg1][0], edges[deg1][1]};
    }
};