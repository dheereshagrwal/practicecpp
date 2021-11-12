#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> ump;
unordered_map<string, bool> ump_;
int static t[1001][1001];
int dp[2][1001][1001];

int recursiveSolve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = recursiveSolve(arr, i, k) + recursiveSolve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp_ans); // take temp minimum value from the temp answers
    }

    return ans;
}
int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        t[i][j] = 0;
        return 0;
    }
    if (t[i][j] != -1)
        return t[i][j];
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp_ans); // take temp minimum value from the temp answers
    }

    return t[i][j] = ans;
}
bool isPalindrome(string s, int i, int j)
{ // function to check either a string is palindrome or not
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
int recursivePalindromePartitioning(string s, int i, int j)
{
    int ans = INT_MAX;
    if (i >= j || isPalindrome(s, i, j))
        return 0;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = recursivePalindromePartitioning(s, i, k) + recursivePalindromePartitioning(s, k + 1, j) + 1;
        ans = min(temp, ans);
    }

    return ans;
}
int palindromePartitioning(string s, int i, int j)
{
    if (t[i][j] != -1)
        return t[i][j];

    if (i >= j || isPalindrome(s, i, j))
    {
        t[i][j] = 0;
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (t[i][k] == -1)
            left = palindromePartitioning(s, i, k);
        else
            left = t[i][k];

        if (t[k + 1][j] == -1)
            right = palindromePartitioning(s, k + 1, j);
        else
            right = t[k + 1][j];

        int temp_ans = left + right + 1;
        ans = min(ans, temp_ans);
    }

    return t[i][j] = ans;
}

int evaluateExpression3D(string s, int i, int j, bool isTrue)
{
    if (i >= j)
    {
        if (isTrue)
            dp[1][i][j] = s[i] == 'T';
        else
            dp[0][i][j] = s[i] == 'F';
        return dp[isTrue][i][j];
    }

    if (dp[isTrue][i][j] != -1)
        return dp[isTrue][i][j];

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int l_T = evaluateExpression3D(s, i, k - 1, true);
        int l_F = evaluateExpression3D(s, i, k - 1, false);
        int r_T = evaluateExpression3D(s, k + 1, j, true);
        int r_F = evaluateExpression3D(s, k + 1, j, false);

        if (s[k] == '|')
        {
            if (isTrue == true)
                ans += l_T * r_T + l_T * r_F + l_F * r_T;
            else
                ans += l_F * r_F;
        }
        else if (s[k] == '&')
        {
            if (isTrue == true)
                ans += l_T * r_T;
            else
                ans += l_T * r_F + l_F * r_T + l_F * r_F;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += l_T * r_F + l_F * r_T;
            else
                ans += l_T * r_T + l_F * r_F;
        }
    }

    dp[isTrue][i][j] = ans;

    return ans;
}

int evaluateExpression(string s, int i, int j, bool isTrue)
{
    string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

    if (ump.find(key) != ump.end())
        return ump[key];

    if (i >= j)
    {
        if (isTrue)
            ump[key] = s[i] == 'T';
        else
            ump[key] = s[i] == 'F';
        return ump[key];
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int l_T = evaluateExpression(s, i, k - 1, true);
        int l_F = evaluateExpression(s, i, k - 1, false);
        int r_T = evaluateExpression(s, k + 1, j, true);
        int r_F = evaluateExpression(s, k + 1, j, false);

        if (s[k] == '|')
        {
            if (isTrue == true)
                ans += l_T * r_T + l_T * r_F + l_F * r_T;
            else
                ans += l_F * r_F;
        }
        else if (s[k] == '&')
        {
            if (isTrue == true)
                ans += l_T * r_T;
            else
                ans += l_T * r_F + l_F * r_T + l_F * r_F;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += l_T * r_F + l_F * r_T;
            else
                ans += l_T * r_T + l_F * r_F;
        }
    }

    return ump[key] = ans;
}

int recursiveEvaluateExpression(string s, int i, int j, bool isTrue)
{
    if (i >= j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int l_T = recursiveEvaluateExpression(s, i, k - 1, true);
        int l_F = recursiveEvaluateExpression(s, i, k - 1, false);
        int r_T = recursiveEvaluateExpression(s, k + 1, j, true);
        int r_F = recursiveEvaluateExpression(s, k + 1, j, false);

        if (s[k] == '|')
        {
            if (isTrue == true)
                ans += l_T * r_T + l_T * r_F + l_F * r_T;
            else
                ans += l_F * r_F;
        }
        else if (s[k] == '&')
        {
            if (isTrue == true)
                ans += l_T * r_T;
            else
                ans += l_T * r_F + l_F * r_T + l_F * r_F;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += l_T * r_F + l_F * r_T;
            else
                ans += l_T * r_T + l_F * r_F;
        }
    }

    return ans;
}

bool recursiveScramabledString(string X, string Y)
{
    if (X.compare(Y) == 0)
        return true;
    if (X.length() <= 1)
        return false;

    int n = X.length();
    int flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        if ((recursiveScramabledString(X.substr(0, i), Y.substr(n - i, i)) && recursiveScramabledString(X.substr(i), Y.substr(0, n - i))) ||
            (recursiveScramabledString(X.substr(0, i), Y.substr(0, i)) && recursiveScramabledString(X.substr(i), Y.substr(i))))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool scramabledString(string X, string Y)
{
    string key = X + " " + Y;
    if (ump_.find(key) != ump_.end())
        return ump_[key];

    if (X.compare(Y) == 0)
    {
        ump_[key] = true;
        return true;
    }
    if (X.length() <= 1)
    {
        ump_[key] = false;
        return false;
    }

    int n = X.length();
    int flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        if ((scramabledString(X.substr(0, i), Y.substr(n - i, i)) && scramabledString(X.substr(i), Y.substr(0, n - i))) ||
            (scramabledString(X.substr(0, i), Y.substr(0, i)) && scramabledString(X.substr(i), Y.substr(i))))
        {
            flag = true;
            break;
        }
    }

    return ump_[key] = flag;
}

int recursiveEggDrop(int eggs, int floors)
{
    if (eggs == 1)
        return floors;
    if (floors == 0 || floors == 1)
        return floors;

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int temp_ans = 1 + max(recursiveEggDrop(eggs - 1, k - 1), recursiveEggDrop(eggs, floors - k)); // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above
        mn = min(mn, temp_ans);
    }

    return mn;
}
int t_[101][101];
int eggDrop(int eggs, int floors)
{
    if (t_[eggs][floors] != -1)
        return t_[eggs][floors];
    if (eggs == 1)
    {
        t_[eggs][floors] = floors;
        return floors;
    }
    if (floors == 0 || floors == 1)
    {
        t_[eggs][floors] = floors;
        return floors;
    }

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int top, bottom;
        if (t_[eggs - 1][k - 1] != -1) // break the temp in sub problemes
            top = t_[eggs - 1][k - 1];
        else
        {
            top = eggDrop(eggs - 1, k - 1);
            t_[eggs - 1][k - 1] = top;
        }

        if (t_[eggs][floors - k] != -1)
            bottom = t_[eggs][floors - k];
        else
        {
            bottom = eggDrop(eggs, floors - k);
            t_[eggs][floors - k] = bottom;
        }
        int temp_ans = 1 + max(top, bottom);
        mn = min(mn, temp_ans);
    }

    return t_[eggs][floors] = mn;
    ;
}

signed main()
{
    // memset(t, -1, sizeof(t));
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // cout << recursiveSolve(arr, 1, n - 1) << endl;

    // string s;
    // cin >> s;

    // memset(t, -1, sizeof(t));

    // cout << palindromePartitioning(s, 0, s.length() - 1) << endl;
    // memset(dp[0], -1, sizeof(dp[0]));
    // memset(dp[1], -1, sizeof(dp[1]));
    // string s;
    // cin >> s;
    // cout << recursiveEvaluateExpression(s, 0, s.length() - 1, true) << endl;
    // string X, Y;
    // cin >> X >> Y;

    // if (X.length() != Y.length())
    //     cout << "No\n";
    // else
    //     recursiveScramabledString(X, Y) ? cout << "Yes\n" : cout << "No\n";

    // int eggs, floors;
    // cin >> eggs >> floors;

    // cout << recursiveEggDrop(eggs, floors) << endl;
    // return 0;
    memset(t_, -1, sizeof(t_));

    // return 0;
}