class Solution
{
public:
    class Disjoint
    {
    public:
        vector<int> parent;
        vector<int> size;

        Disjoint(int n)
        {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int u)
        {
            if (u == parent[u])
                return u;

            return parent[u] = findParent(parent[u]);
        }

        bool unionBySize(int u, int v)
        {
            int ultp_u = findParent(u);
            int ultp_v = findParent(v);

            if (ultp_u == ultp_v)
                return false;

            else if (size[ultp_u] < size[ultp_v])
            {
                parent[ultp_u] = ultp_v;
                size[ultp_v] += size[ultp_u];
            }
            else
            {
                parent[ultp_v] = ultp_u;
                size[ultp_u] += size[ultp_v];
            }
            return true;
        }
    };

    bool static cmp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] > v2[0];
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &e)
    {
        Disjoint bob(n);
        Disjoint alice(n);

        sort(e.begin(), e.end(), cmp);
        int count = 0;
        int bs = 0;
        int as = 0;
        for (int i = 0; i < e.size(); i++)
        {
            int u = e[i][1];
            int v = e[i][2];
            int t = e[i][0];

            if (t == 3)
            {
                bool b1 = bob.unionBySize(u, v);
                bool b2 = alice.unionBySize(u, v);
                if (b1 == false && b1 == false)
                {
                    count++;
                }
                if (b1 == true)
                    bs++;
                if (b2 == true)
                    as++;
            }
            else if (t == 2)
            {
                bool b1 = bob.unionBySize(u, v);
                if (b1 == false)
                {
                    count++;
                }
                if (b1 == true)
                    bs++;
            }
            else
            {
                bool b1 = alice.unionBySize(u, v);
                if (b1 == false)
                {
                    count++;
                }
                if (b1 == true)
                    as++;
            }
        }
        if (bs != n - 1 || as != n - 1)
            return -1;

        return count;
    }
};