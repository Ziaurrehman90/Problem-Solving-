class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        int number_of_nodes = n;
        vector<vector<vector<int>>> adjList(n + 1);
        for (auto &it : edges)
        {
            adjList[it[0]].push_back({it[1], 0});
            adjList[it[1]].push_back({it[0], 1});
        }
        vector<int> visited(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (node == dst)
            {
                return cost;
            }
            if (visited[node])
                continue;
            visited[node] = 1;
            for (auto &it : adjList[node])
            {
                int next = it[0], nc = cost + it[1];
                if (!visited[next])
                    pq.push({nc, next});
            }
        }
        return -1;
    }
};