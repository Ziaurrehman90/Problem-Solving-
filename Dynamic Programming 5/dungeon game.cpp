class Solution
{
    int n, m;
    int dfs(int x, int y, vector<vector<int>> &nums, vector<vector<int>> &dp)
    {
        if (x >= n || x < 0 || y >= m || y < 0)
            return INT_MIN;
        if (x == n - 1 && y == m - 1)
            return nums[x][y];
        if (dp[x][y] != -1)
            return dp[x][y];
        int ans = nums[x][y];
        int val = nums[x][y] + max(dfs(x + 1, y, nums, dp), dfs(x, y + 1, nums, dp));
        return dp[x][y] = min(ans, val);
    }

public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        n = dungeon.size();
        m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int val = dfs(0, 0, dungeon, dp);
        if (val >= 0)
            return 1;
        else
        {
            val = -1 * val;
            return val + 1;
        }
    }
};