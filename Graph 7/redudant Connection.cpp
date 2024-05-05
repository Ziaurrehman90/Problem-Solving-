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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> temp = edges[i];
            int u = temp[0];
            int v = temp[1];
            if (ds.findUpar(u) == ds.findUpar(v))
            {
                ans.push_back(u);
                ans.push_back(v);
                return ans;
            }
            ds.UniounByRank(u, v);
        }
        return ans;
    }
};