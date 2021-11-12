#include <iostream>
using namespace std;
void toh(int n, char s, char d, char h, int &count)
{
    count++;
    if (n == 1)
    {
        cout << "Moved from " << s << " to " << d << endl;
        return;
    }
    toh(n - 1, s, h, d, count);
    cout << "Moved from " << s << " to " << d << endl;
    toh(n - 1, h, d, s, count);
}
