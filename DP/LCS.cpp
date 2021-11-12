#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int t[1001][1001];

// bool isPalindrome(string s, int i, int j)
// { // function to check either a string is palindrome or not
//     while (i <= j)
//     {
//         if (s[i] != s[j])
//             return false;
//         i++, j--;
//     }
//     return true;
// }
int RecursiveLCS(string X, string Y, int m, int n)
{

    if (m == 0 || n == 0)
        t[m][n] = 0;

    if (t[m][n] != -1)
        return t[m][n];

    if (X[m - 1] == Y[n - 1])
        t[m][n] = 1 + RecursiveLCS(X, Y, m - 1, n - 1);
    else
        t[m][n] = max(RecursiveLCS(X, Y, m - 1, n), RecursiveLCS(X, Y, m, n - 1)); // one take full and another by leaving last char
    return t[m][n];
}
int LCS(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[m][n];
}

int allCS(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        t[m][n] = 0;

    if (t[m][n] != -1)
        return t[m][n];

    if (X[m - 1] == Y[n - 1])
        t[m][n] = 1 + allCS(X, Y, m - 1, n) + allCS(X, Y, m, n - 1);
    else
        t[m][n] = allCS(X, Y, m - 1, n) + allCS(X, Y, m, n - 1) - allCS(X, Y, m - 1, n - 1);
    return t[m][n];
}
int DOS(string src, string tar, int m, int n)
{
    if (m == 0)
        t[m][n] = 0;
    if (n == 0)
        t[m][n] = 1;
    if (t[m][n] != -1)
        return t[m][n];

    if (src[m - 1] != tar[n - 1])
        t[m][n] = DOS(src, tar, m - 1, n);
    else
        t[m][n] = DOS(src, tar, m - 1, n) + DOS(src, tar, m - 1, n - 1);
    return t[m][n];
}

int LCSubstring(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }

    int mx = INT_MIN;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            mx = max(mx, dp[i][j]);

    // for (int i = 0; i < m + 1; i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < n + 1; j++)
    //         cout << dp[i][j] << " ";
    // }
    cout << endl;
    return mx;
}

string printLCS(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    string s = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    // cout << s.length() << endl;
    reverse(s.begin(), s.end());
    return s;
}

string printLCSubstring(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    string s = "";
    int current_max = 0;
    int old_max = 0;
    for (int i = m; i > 0; i--)
        for (int j = n; j > 0; j--)
        {
            if (dp[i][j] >= 1)
            {
                old_max = current_max;
                current_max = max(current_max, dp[i][j]);
                if (current_max > old_max)
                {
                    s = "";
                    for (int k = 0; k < current_max; k++)
                        s.push_back(X[i - 1 - k]);
                }
            }
        }
    reverse(s.begin(), s.end());
    return s;
}
int SCS(string X, string Y, int m, int n)
{
    return m + n - LCS(X, Y, m, n); // formula // n-> length of string x ; m-> length of string y
}
string printSCS(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    string s = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            s.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                s.push_back(Y[j - 1]);
                j--;
            }
            else
            {
                s.push_back(X[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(X[i - 1]);
        i--;
    }

    while (j > 0)
    {
        s.push_back(Y[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

void minInsertionDeletion(string X, string Y, int m, int n)
{
    int lcs_len = LCS(X, Y, m, n);
    cout << "Minimum number of deletions = " << (m - lcs_len) << endl;
    cout << "Minimum number of insertions = " << (n - lcs_len) << endl;
}
int LPS(string X, int m)
{
    string Y = X;
    reverse(Y.begin(), Y.end());
    cout << "Length of palindromic sequence is " << LCS(X, Y, m, m);
    cout << endl;
    cout << printLCS(X, Y, m, m);
    return LCS(X, Y, m, m);
}
int minimumInsertionsDeletionsToMakePalindrome(string X, int m)
{
    return m - LPS(X, m);
}

int LRS(string X, int m)
{
    int n = m;
    int dp[m + 1][n + 1];
    string Y = X;
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[m][n];
}

string printLRS(string X, int m)
{
    int n = m;
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (X[i - 1] == X[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    string s = "";

    // Traverse dp[][] from bottom right
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            s.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }

    // Since we traverse dp[][] from bottom,
    // we get result in reverse order.
    reverse(s.begin(), s.end());

    return s;
}
bool sequencePatternMatching(string X, string Y, int m, int n)
{
    return (m == LCS(X, Y, m, n)) ? true : false;
}
int TPS(string X, int start, int m)
{
    int end = m - 1;
    if (start > end)
        t[start][m] = 0;
    if (t[start][m] != -1)
        return t[start][m];
    if (start == end)
        t[start][m] = 1;
    if (X[start] == X[end])
        t[start][m] = 1 + TPS(X, start, m - 1) + TPS(X, start + 1, m);
    else
        t[start][m] = TPS(X, start, m - 1) + TPS(X, start + 1, m) - TPS(X, start + 1, m - 1);
    return t[start][m];
}
// int TPS_(string X, int start, int m)
// {
//     int dp[start][m];
//     for (int i = 0; i < start + 1; i++)
//         for (int j = 0; j < m + 1; j++)
//         {
//             if (i > j)
//                 dp[i][j] = 0;
//             else if (i == j - 1)
//                 dp[i][j] = 1;
//         }
//     for (int i = 1; i < start + 1; i++)
//         for (int j = 1; j < m + 1; j++)
//         {
//             if (X[i] == X[j - 1])
//                 dp[i][j] = 1 + dp[i][j - 1] + dp[i + 1][j];
//             else
//                 dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
//         }

//     return dp[start][m];
// }

int main()
{
    string X, Y;
    // cin >> X >> Y;
    // int m = X.length(), n = Y.length();
    // memset(t, -1, sizeof(t));
    // cout << LCS(X, Y, n, m) << endl;
    // X = "hippopotamus";
    // Y = "rhinoceros";
    // int m = X.length(), n = Y.length();
    // cout << printLCS(X, Y, m, n) << endl;

    // cout << minimumDeletionsToMakePalindrome(X, m) << endl;
    // cout << printSCS(X, Y, m, n) << endl;

    // cin >> X;
    // int n = X.length();
    // cout << TPS(X, 0, n);
    // X = "ajblqcpdz";
    // Y = "aefcnbtdi";

    string src = "geeksforgeeks";
    string tar = "ge";
    memset(t, -1, sizeof(t));
    int m = src.size();
    int n = tar.size();
    cout << DOS(src, tar, m, n) << endl;
    // cout << LCS(X, Y, m, n) << endl;

    // return 0;
}