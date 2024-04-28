class Solution
{
public:
    int cycle_length = INT_MAX;
    void bfs(int n, vector<int> adjList[], vector<vector<int>> &edges, int source)
    {

        // 1 parent array bna lete h jo cycle ko detect krne k kaam aata h
        vector<int> parent(n, -1);
        // 1 distance vector bna lete h jo yeh btayega k parent node s dusre node ka kitna distance h
        vector<int> distance(n, INT_MAX);
        // 1 queue bna leta hn bfs travesal k liye
        queue<int> q;
        q.push(source);
        distance[source] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &child : adjList[node])
            {
                if (distance[child] == INT_MAX)
                {
                    distance[child] = 1 + distance[node];
                    parent[child] = node;
                    q.push(child);
                }
                // cycle deterct hone ki condition kya h k wo alreadt visited h but u node jo h ow uski parent ni h tou obviously cycle hogi

                else if (parent[child] != node && parent[node] != child)
                {
                    // length of cycle kitni hogi
                    // dono k distance k barabar hogi
                    cycle_length = min(cycle_length, 1 + distance[child] + distance[node]);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        // adjacency lisy bna lete h
        vector<int> adjList[n];
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        // component wali situation h ou hr nod epr bfs calll krna padega
        for (int i = 0; i < n; i++)
        {
            bfs(n, adjList, edges, i);
        }
        if (cycle_length == INT_MAX)
        {
            return -1;
        }
        return cycle_length;
    }
};