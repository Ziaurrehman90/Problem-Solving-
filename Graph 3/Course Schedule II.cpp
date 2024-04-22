class Solution
{
public:
    vector<int> ans;
    bool dfs(int source, vector<int> &visited, vector<int> &pathVisited, vector<int> adjList[])
    {
        visited[source] = 1;
        pathVisited[source] = 1;
        for (auto &child : adjList[source])
        {
            if (!visited[child])
            {
                if (dfs(child, visited, pathVisited, adjList) == true)
                {
                    return true;
                }
            }
            else if (pathVisited[child])
            {
                return true;
            }
        }
        pathVisited[source] = 0;
        ans.push_back(source);
        return false;
    }
    bool final(int numCourses, vector<vector<int>> &prerequisites)
    {

        int n = prerequisites.size();
        // sabse phle adjacency list create kr leta hn wo bhi directed graph ki

        vector<int> adjList[numCourses];
        for (auto &edge : prerequisites)
        {
            adjList[edge[0]].push_back(edge[1]);
        }
        // now ab cyclic detection ka concept laga dete h
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, pathVisited, adjList) == true)
                {
                    return false;
                }
            }
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // vector<int>ans;
        if (final(numCourses, prerequisites) == false)
        {
            return {};
        }

        return ans;
    }
};