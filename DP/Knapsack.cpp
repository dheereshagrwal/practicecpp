#include <iostream>
#include <cstring>
#include <limits>
#include <vector>
#include <typeinfo>
#define I numeric_limits<int>::max()
using namespace std;

int recursiveKnapsack(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    memset(t, -1, sizeof(t));
    if (t[n][w] == -1)
        return t[n][w];
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return t[n][w] = max((val[n - 1] + recursiveKnapsack(wt, val, w - wt[n - 1], n - 1)), (recursiveKnapsack(wt, val, w, n - 1)));
    else if (wt[n - 1] < w)
        return t[n][w] = recursiveKnapsack(wt, val, w, n - 1);
    return 0;
}

int BUKnapsack(int wt[], int val[], int w, int n)
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
                t[i][j] = max((val[i - 1] + t[i - 1][j - wt[i - 1]]), (t[i - 1][j]));
            else if (wt[i - 1] < j)
                t[i][j] = t[i - 1][j];
        }

    return 0;
}

bool subsetSum(int arr[], int sum, int n, int lastRowOfSubsetSum[])
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
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }

    for (int j = 0; j < sum + 1; j++)
        lastRowOfSubsetSum[j] = t[n][j];
    return t[n][sum];
}

int equalSumPartition(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    int lastRowOfSubsetSum[sum + 1];

    if (sum % 2 != 0)
        return 0;
    else if (sum % 2 == 0)
        return subsetSum(arr, sum / 2, n, lastRowOfSubsetSum);
    return 0;
}
int countSubsetSum(int arr[], int sum, int n)
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
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}
int minimumSubsetSumDifference(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range = range + arr[i];
    // Now declare range and such
    int lastRowOfSubsetSum[range + 1];
    subsetSum(arr, range, n, lastRowOfSubsetSum);
    // take the value till half

    vector<int> v;
    for (int i = 0; i <= (range + 1) / 2; i++)
    {
        if (lastRowOfSubsetSum[i] == 1)
            v.push_back(i);
    }
    cout << "My vector is" << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    int mn = I;
    for (int i = 0; i < v.size(); i++)
        mn = min(mn, range - 2 * v[i]);

    return mn;
}

int countSubsetGivenDifference(int arr[], int diff, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range = range + arr[i];
    int sum = (diff + range) / 2;
    return countSubsetSum(arr, sum, n);
}
int targetSum(int arr[], int diff, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range = range + arr[i];
    int sum = (diff + range) / 2;
    return countSubsetSum(arr, sum, n);
}

int main(void)
{
    // int arr[] = {2, 3, 7, 8, 10};
    // int lastRowOfSubsetSum[11];
    // cout << subsetSum(arr, 10, 5, lastRowOfSubsetSum) << endl;
    int arr[] = {1, 2, 7};
    cout << countSubsetGivenDifference(arr, 8, 3) << endl;
}
