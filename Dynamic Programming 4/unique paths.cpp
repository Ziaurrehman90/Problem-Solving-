class Solution
{
public:
    // recursion
    /*int f(int i,int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        int left=f(i,j-1);
        int right=f(i-1,j);
        return left+right;

    }*/
    // memoization
    int f(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = f(i, j - 1, dp);
        int right = f(i - 1, j, dp);

        return dp[i][j] = left + right;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};