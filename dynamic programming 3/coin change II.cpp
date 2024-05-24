class Solution
{
public:
    int f(vector<int> &coins, int index, int target, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[0] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        int non_take = f(coins, index - 1, target, dp);
        int take = 0;
        if (coins[index] <= target)
        {
            take = f(coins, index, target - coins[index], dp);
        }
        return dp[index][target] = take + non_take;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(coins, n - 1, amount, dp);
    }
};