class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        int cum_sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {

            cum_sum = cum_sum + nums[i];
            maximum = maximum > cum_sum ? maximum : cum_sum;
            if (cum_sum < 0)
            {
                cum_sum = 0;
            }
        }
        return maximum;
    }
};