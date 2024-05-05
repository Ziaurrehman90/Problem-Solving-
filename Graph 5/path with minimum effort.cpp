#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution
{
public:
    int minimumEffortPath(std::vector<std::vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::unordered_set<std::pair<int, int>, std::hash<std::pair<int, int>>> visited;
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
        pq.emplace(0, 0, 0);

        while (!pq.empty())
        {
            auto [row, col, efforts] = pq.top();
            pq.pop();

            if (visited.count({row, col}))
                continue;
            visited.insert({row, col});

            if (row == m - 1 && col == n - 1)
                return efforts;

            for (const auto &[a, b] : directions)
            {
                int newRow = row + a;
                int newCol = col + b;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n)
                {
                    int newEfforts = std::max(efforts, std::abs(heights[row][col] - heights[newRow][newCol]));
                    pq.emplace(newRow, newCol, newEfforts);
                }
            }
        }

        return -1;
    }
};
