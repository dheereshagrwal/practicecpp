#include <bits/stdc++.h>
using namespace std;
pair<int, int> binSearch2D(int mat[4][4], int start, int end, int ele)
{
    int n = 4;
    int m = 4;
    int i = 0;
    int j = m - 1;
    while (i >= 0 and i < n and j >= 0 and j < m)
    {
        if (mat[i][j] == ele)
            return {i, j};
        else if (mat[i][j] > ele)
            j--;
        else if (mat[i][j] < ele)
            i++;
    }
    return {-1, -1};
}
int main(void)
{
    int mat[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    // 2DBinSearch(mat, 0, 4, 29);
}