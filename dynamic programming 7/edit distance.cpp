class Solution
{
public:
    // int minDistance(string word1, string word2) {

    // }
    // int f(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    /// base cas 4w
    // s1 exhaust ho ri h tou
    //  if(i<0){
    //      return j+1;
    //  }
    //  if(j<0){
    //      return i+1;
    //  }
    //  if(dp[i][j]!=-1){
    //      return dp[i][j];
    //  }

    // match condtion
    //  if(s[i]==t[j]){
    //      return dp[i][j]= 0+f(s,t,i-1,j-1,dp);
    //  }
    //  not match
    //   case 1 insertion
    //  f(s,t,i,j-1);
    //  case 2 deletion
    //  f(s,t,i-1,j);
    // case 3 : replacement
    //  f(s,t,i-1,j-1);
    //  return dp[i][j]= 1+min( f(s,t,i,j-1,dp),min(f(s,t,i-1,j,dp), f(s,t,i-1,j-1,dp)));
    // }
    int minDistance(string str1, string str2)
    {
        // write you code here
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i + 1;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = j + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m] - 1;
    }
};