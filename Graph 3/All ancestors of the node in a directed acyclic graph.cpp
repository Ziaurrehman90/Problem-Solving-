class Solution
{
public:
    void dfs(int node, vector<int> adjList[], vector<int> &temp, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto &child : adjList[node])
        {

            if (!visited[child])
            {
                temp.push_back(child);
                dfs(child, adjList, temp, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        //    sabse aasam tarika h k m hr node ki ancestors leta rhu
        // tou isi baat pr adjacency list create kr dete h
        vector<int> adjList[n];
        for (auto &edge : edges)
        {
            adjList[edge[1]].push_back(edge[0]);
        }
        //    ab kya kre ?
        // hr node pr dfs call krte rhenge or nodes k adjacent ko vector m daalte rhenge
        // sabse phle ans k liye 1 vector bna leta hn
        vector<vector<int>> ans(n);
        // dfs 0 s shuru krunga
        for (int i = 0; i < n; i++)
        {
            // yeh wo vector h jusme us nodes k sare ancestors store honge
            vector<int> temp;
            // visited bhi bna leta hnn
            vector<int> visited(n, 0);
            // now dfs call kr deta hn
            dfs(i, adjList, temp, visited);
            // sort krde as per question
            sort(temp.begin(), temp.end());
            ans[i] = temp;
        }
        return ans;
    }
};