#include <iostream>
#include <cstring>
#include <limits>
#include <vector>
#include <typeinfo>
#define I numeric_limits<int>::max()
using namespace std;
int recursiveUnboundedKnapsack(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    memset(t, -1, sizeof(t));
    if (t[n][w] == -1)
        return t[n][w];
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return t[n][w] = max((val[n - 1] + recursiveUnboundedKnapsack(wt, val, w - wt[n - 1], n)), (recursiveUnboundedKnapsack(wt, val, w, n - 1)));
    else if (wt[n - 1] < w)
        return t[n][w] = recursiveUnboundedKnapsack(wt, val, w, n - 1);
    return 0;
}

int TDUnboundedKnapsack(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < w + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max((val[i - 1] + t[i][j - wt[i - 1]]), (t[i - 1][j]));
            else if (wt[i - 1] < j)
                t[i][j] = t[i - 1][j];
        }

    return 0;
}

int rodCutting(int price[], int length[], int N, int n)
{
    int t[n + 1][N + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < N + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < N + 1; j++)
        {
            if (price[i - 1] <= j)
                t[i][j] = max((price[i - 1] + t[i][j - price[i - 1]]), (t[i - 1][j]));
            else if (price[i - 1] < j)
                t[i][j] = t[i - 1][j];
        }
    return 0;
}
int coinChange(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}

int minimumCoinChange(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = I - 1;
            if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    t[i][j] = j / coins[i - 1];
                else
                    t[i][j] = I - 1;
            }
        }
    }
    t[0][0] = I - 1;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = min((1 + t[i][j - coins[i - 1]]), (t[i - 1][j]));
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}

int main(void)
{
    // int price[] = {3, 4, 9, 13, 15, 17, 20, 6};
    // int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int n = 8;
    // int N = 50;
    // rodCutting(price, length, N, n);
    int coins[] = {1, 2, 3};
    cout << minimumCoinChange(coins, 6, 3) << endl;
}