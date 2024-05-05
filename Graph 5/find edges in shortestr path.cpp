class Solution
{
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {

        vector<bool> ans(edges.size(), false);

        vector<int> dist(n, INT_MAX);

        vector<pair<int, int>> adj[n];

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        dist[0] = 0;

        vector<vector<int>> bestPar(n);

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int d = it.second;
                if (dis + d < dist[adjNode])
                {
                    bestPar[adjNode].clear();

                    bestPar[adjNode].push_back(node);
                    dist[adjNode] = dis + d;
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dis + d == dist[adjNode])
                {
                    bestPar[adjNode].push_back(node);
                }
            }
        }

        if (dist[n - 1] == INT_MAX)
            return ans;
        cout << dist[n - 1];
        map<pair<int, int>, bool> mp;

        vector<int> dests;
        dests.push_back(n - 1);

        for (int i = 0; i < dests.size(); i++)
        {
            for (auto best : bestPar[dests[i]])
            {
                dests.push_back(best);
                mp[{dests[i], best}] = true;
                mp[{best, dests[i]}] = true;
            }
        }

        int i = 0;

        for (auto it : edges)
        {
            if (mp[{it[0], it[1]}] == true or mp[{it[1], it[0]}] == true)
            {
                ans[i] = true;
            }
            else
                ans[i] = false;
            i++;
        }

        return ans;
    }
};