class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, vector<vector<int>> &movecost)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (i == 0)
        {
            return grid[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 1e9;
        for (int k = 0; k < grid[0].size(); k++)
        {

            int path = grid[i][j] + f(i - 1, k, grid, dp, movecost) + movecost[grid[i - 1][k]][j];
            ans = min(ans, path);
        }
        return dp[i][j] = ans;
    }
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        //  return f(m-1,n-1,grid,dp,movecost);
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, f(n - 1, i, grid, dp, moveCost));
        }
        return ans;
    }
};