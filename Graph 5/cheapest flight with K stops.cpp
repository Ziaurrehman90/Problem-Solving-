#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k)
{
    std::unordered_map<int, std::vector<std::pair<int, int>>> neighbors;
    for (const auto &flight : flights)
    {
        neighbors[flight[0]].emplace_back(flight[2], flight[1]);
    }

    std::priority_queue<std::tuple<int, int, int>> queue;
    queue.emplace(0, src, k);
    std::unordered_map<int, int> visited;
    visited[src] = k;

    while (!queue.empty())
    {
        int price, city, remaining;
        std::tie(price, city, remaining) = queue.top();
        queue.pop();

        if (city == dst)
        {
            return price;
        }

        if (remaining >= 0)
        {
            for (const auto &[cost, to] : neighbors[city])
            {
                if (visited.count(to) && visited[to] >= remaining)
                {
                    continue;
                }
                int nextPrice = price + cost;
                auto it = std::lower_bound(queue.begin(), queue.end(), std::make_tuple(nextPrice, to, remaining - 1),
                                           [](const auto &a, const auto &b)
                                           {
                                               return std::get<0>(a) < std::get<0>(b);
                                           });
                queue.emplace(nextPrice, to, remaining - 1);
                visited[to] = remaining - 1;
            }
        }
    }

    return -1;
}
