class Solution
{
public:
    int f(vector<int> &coins, int index, int target, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[0] == 0)
            {
                return target / coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        int non_take = 0 + f(coins, index - 1, target, dp);
        int take = 1e9;
        if (coins[index] <= target)
        {
            take = 1 + f(coins, index, target - coins[index], dp);
        }
        return dp[index][target] = min(take, non_take);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        if (amount == 0)
        {
            return 0;
        }
        int ans = f(coins, n - 1, amount, dp);
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};