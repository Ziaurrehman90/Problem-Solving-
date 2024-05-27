#include <iostream>
#include <vector>
#include <algorithm>

int solve(int n)
{
    std::vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = std::min(dp[i / 2] + 1, dp[i]);
        }
        if (i % 3 == 0)
        {
            dp[i] = std::min(dp[i / 3] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main(int argc, char *argv[])
{
    int n1 = 9, n2 = 8;
    std::cout << solve(n1) << std::endl;
    std::cout << solve(n2) << std::endl;
    return 0;
}
