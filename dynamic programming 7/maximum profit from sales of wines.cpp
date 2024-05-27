#include <bits/stdc++.h>
using namespace std;

#define MAX_WINES 1000

int profitMemo[MAX_WINES][MAX_WINES];
int optimalAction[MAX_WINES][MAX_WINES];

int calculateMaxProfit(int prices[], int start, int end, int totalWines)
{
    if (profitMemo[start][end] != -1)
        return profitMemo[start][end];

    int currentYear = totalWines - (end - start);

    if (start == end)
        return currentYear * prices[start];

    int profitIfSoldFromStart = prices[start] * currentYear +
                                calculateMaxProfit(prices, start + 1, end, totalWines);
    int profitIfSoldFromEnd = prices[end] * currentYear +
                              calculateMaxProfit(prices, start, end - 1, totalWines);

    int maxProfit = max(profitIfSoldFromStart, profitIfSoldFromEnd);
    profitMemo[start][end] = maxProfit;

    if (profitIfSoldFromStart >= profitIfSoldFromEnd)
        optimalAction[start][end] = 0;
    else
        optimalAction[start][end] = 1;

    return maxProfit;
}

void initializeMemoTables()
{
    for (int i = 0; i < MAX_WINES; i++)
    {
        for (int j = 0; j < MAX_WINES; j++)
        {
            profitMemo[i][j] = -1;
        }
    }
}

void printOptimalSellingOrder(int totalWines)
{
    int start = 0, end = totalWines - 1;

    while (start <= end)
    {
        if (optimalAction[start][end] == 0)
        {
            cout << "beg ";
            start++;
        }
        else
        {
            cout << "end ";
            end--;
        }
    }
    cout << endl;
}

int getMaxProfit(int prices[], int totalWines)
{
    initializeMemoTables();

    int maxProfit = calculateMaxProfit(prices, 0, totalWines - 1, totalWines);

    printOptimalSellingOrder(totalWines);

    return maxProfit;
}

int main()
{

    int prices[] = {2, 4, 6, 2, 5};
    int totalWines = sizeof(prices) / sizeof(prices[0]);

    int maxProfit = getMaxProfit(prices, totalWines);

    cout << maxProfit << endl;

    return 0;
}
