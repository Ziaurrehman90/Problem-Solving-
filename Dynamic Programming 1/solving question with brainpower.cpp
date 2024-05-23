class Solution
{
public:
    long long f(vector<vector<int>> &questions, int index, vector<long long> &dp)
    {
        int n = questions.size();
        if (index >= n)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        long long left = questions[index][0] + f(questions, index + questions[index][1] + 1, dp);
        long long right = f(questions, index + 1, dp);
        return dp[index] = max(left, right);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        return f(questions, 0, dp);
    }
};