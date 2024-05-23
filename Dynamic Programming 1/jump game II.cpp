class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> numJumps(nums.size(), 0);
        for (int l = 0, r = 1; l < nums.size() - 1 && r < nums.size(); l++)
        {
            while (r <= l + nums[l] && r < nums.size())
            {
                numJumps[r++] = numJumps[l] + 1;
            }
        }
        return numJumps[nums.size() - 1];
    }
};