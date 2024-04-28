class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {

        //         dijakisttra s krra hn but tle ku d rha  h yeh ??
        vector<int> zia(n, numeric_limits<int>::max());
        zia[0] = 0;

        map<int, vector<pair<int, int>>> List;
        for (const auto &edge : edges)
        {
            int xx = edge[0], yy = edge[1], weight = edge[2];
            List[xx].push_back({yy, weight});
            List[yy].push_back({xx, weight});
        }

        set<pair<int, int>> st;
        st.insert({0, 0});

        while (!st.empty())
        {
            auto it = st.begin();
            int nude = it->second;
            int distance = it->first;
            st.erase(it);

            for (const auto &i : List[nude])
            {
                int temp = i.first;
                int temp1 = i.second;
                if (zia[temp] > temp1 + zia[nude])
                {
                    if (zia[temp] != numeric_limits<int>::max())
                    {
                        st.erase({zia[temp], temp});
                    }
                    zia[temp] = temp1 + zia[nude];
                    if (zia[temp] < disappear[temp])
                    {
                        st.insert({zia[temp], temp});
                    }
                }
            }
        }

        vector<int> malik(n);
        for (int i = 0; i < n; ++i)
        {
            if (disappear[i] <= zia[i])
            {
                malik[i] = -1;
            }
            else
            {
                malik[i] = zia[i];
            }
        }

        return malik;
    }
};