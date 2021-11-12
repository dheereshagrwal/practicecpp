#include <iostream>
using namespace std;
double e(int x, int n)
{
    static double r;
    if (n == 0)
    {
        return r;
    }

    r = 1 + x * (r / n);
    return e(x, n - 1);
}
int main(void)
{
    cout << e(2, 10) << endl;
}