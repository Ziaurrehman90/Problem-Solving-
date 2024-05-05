class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> cmt(n + 1, INT_MAX);
        cmt[k] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            bool flag = false;
            for (auto node : times)
            {
                int src = node[0], des = node[1], time = node[2];
                if (cmt[src] != INT_MAX && cmt[des] > cmt[src] + time)
                    cmt[des] = cmt[src] + time, flag = true;
            }
            if (!flag)
                break;
        }
        if (count(cmt.begin(), cmt.end(), INT_MAX) > 1)
            return -1;
        return *max_element(++(cmt.begin()), cmt.end());
    }
};