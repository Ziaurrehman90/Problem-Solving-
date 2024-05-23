class Solution
{
public:
    // memoization sollution

    /*  int stairs(int n , vector<int>&dp){
          if(n==0){
              return 1;
          }
          if(n==1){
              return 1;
          }
          if(dp[n]!=-1){
              return dp[n];
          }
          return dp[n]=stairs(n-1,dp)+stairs(n-2,dp);
      }*/

    // tabular format
    /* int climbStairs(int n) {
         vector<int>dp(n+1,-1);
         dp[0]=1;
         dp[1]=1;
         for(int i=2;i<=n;i++){
             dp[i]=dp[i-1]+dp[i-2];
         }
         return dp[n];



     }*/
    int climbStairs(int n)
    {
        int prev2 = 1;
        int prev1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};