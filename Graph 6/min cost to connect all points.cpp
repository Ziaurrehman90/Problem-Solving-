class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int min_cost = 0;
        vector<vector<pair<int, int>>> edges(points.size());
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0], y = points[i][1];
            for (int j = i + 1; j < points.size(); j++)
            {
                edges[i].push_back({abs(x - points[j][0]) + abs(y - points[j][1]), j});
                edges[j].push_back({abs(x - points[j][0]) + abs(y - points[j][1]), i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(points.size(), false);
        pq.push({0, 0});
        int n = 0;
        while (!pq.empty())
        {
            pair<int, int> f = pq.top();
            pq.pop();
            if (visited[f.second])
                continue;
            visited[f.second] = true;
            min_cost += f.first;
            n++;
            if (n == points.size())
                break;
            for (auto e : edges[f.second])
            {
                if (!visited[e.second])
                {
                    pq.push(e);
                }
            }
        }
        return min_cost;
            
    }
};