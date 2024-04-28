class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int maximum = INT_MIN;
        int sum = 0;
        int n = cardPoints.size();
        int i, j;
        for (i = 0; i < k; i++)
        {
            sum = sum + cardPoints[i];
        }
        maximum = max(sum, maximum);
        i = k - 1;
        for (j = n - 1; j >= n - k; j--)
        {
            sum = sum + cardPoints[j] - cardPoints[i--];
            maximum = max(sum, maximum);
        }
        return maximum;
    }
};