class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {

        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1, start});

        vector<double> nodeProbsArr(n);
        nodeProbsArr[start] = 1;

        while (!pq.empty())
        {

            auto tp = pq.top();
            pq.pop();
            double currNodeProb = tp.first;
            int currNode = tp.second;

            if (currNode == end)
                return currNodeProb;

            for (auto neighbour : graph[currNode])
            {

                int nextNode = neighbour.first;
                double nextNodeProb = neighbour.second;
                if (nodeProbsArr[nextNode] < nextNodeProb * currNodeProb)
                {
                    nodeProbsArr[nextNode] = nextNodeProb * currNodeProb;
                    pq.push({nodeProbsArr[nextNode], nextNode});
                }
            }
        }
        return 0;
    }
};