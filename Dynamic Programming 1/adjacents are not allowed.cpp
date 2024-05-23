int maxSum(int n, vector<vector<int>> mat)
{
    // code here
    // vector<int>dp(n+1,0);
    int f = 0;
    int s = max(mat[0][0], mat[1][0]);
    if (n == 1)
        return s;
    for (int i = 2; i <= n; i++)
    {
        int curr = max(max(mat[0][i - 1], mat[1][i - 1]) + f, s);
        f = s;
        s = curr;
    }
    return s;
}