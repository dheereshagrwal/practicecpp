#include <bits/stdc++.h>
using namespace std;
char prevLetter(char s[], int start, int end, char ele)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == s[mid])
            return s[mid];
        if (ele > s[mid])
        {
            res = s[mid];
            start = mid + 1;
        }
        else if (ele < s[mid])
            end = mid - 1;
    }
    return res;
}
char nextLetter(char s[], int start, int end, char ele)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ele == s[mid])
            return s[mid];
        if (ele < s[mid])
        {
            res = s[mid];
            end = mid - 1;
        }
        else if (ele > s[mid])
            start = mid + 1;
    }
    return res;
}
int main(void)
{
    char s[] = {'a', 'c', 'f', 'm'};
    int n = *(&s + 1) - s;
    cout << nextLetter(s, 0, n - 1, 'd');
    cout << endl;
}