class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> adjList(n);
        for (auto &it : edges)
        {
            adjList[it[0]].push_back(it[1]);
        }
        for (auto &it : adjList)
        {
            for (int node : it)
            {
                indegree[node]++;
            }
        }
        vector<int> zia;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                zia.push_back(i);
            }
        }
        return zia;
    }
};