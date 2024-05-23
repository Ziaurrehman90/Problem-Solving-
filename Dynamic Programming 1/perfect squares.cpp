class Solution
{
public:
    bool is_perfect_square(int n)
    {
        int p = n;
        int z = sqrt(n);
        return z * z == p;
    }
    int f(vector<int> &ans, int target, int index, vector<vector<int>> &dp)
    {
        // base case
        if (target == 0)
        {
            return 0;
        }
        if (index >= ans.size() || target < 0)
        {
            return 1e9;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int take = 1e9, non_take = 0;
        non_take = 0 + f(ans, target, index + 1, dp);
        if (ans[index] <= target)
        {
            take = 1 + f(ans, target - ans[index], index, dp);
        }
        return dp[index][target] = min(take, non_take);
    }
    int numSquares(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (is_perfect_square(i))
            {
                ans.push_back(i);
            }
        }
        int p = ans.size();
        vector<vector<int>> dp(p, vector<int>(n + 1, -1));
        return f(ans, n, 0, dp);
    }
};