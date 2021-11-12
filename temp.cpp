// // #include <iostream>
// // using namespace std;
// // int main(void)
// // {
// //     // int A[] = {
// //     //     10,
// //     //     11,
// //     //     21,
// //     // };
// //     // int *p = A;
// //     // cout << p[2] << endl;

// // }

// #include <iostream>
// #include <limits>

// using namespace std;

// // template <typename T>
// // void showMinMax()
// // {
// //     cout << "min: " << numeric_limits<T>::min() << endl;
// //     cout << "max: " << numeric_limits<T>::max() << endl;
// //     cout << endl;
// // }

// int main()
// {

//     // cout << "short:" << endl;
//     // showMinMax<short>();
//     // cout << "int:" << endl;
//     // showMinMax<int>();
//     // cout << "long:" << endl;
//     // showMinMax<long>();
//     // cout << "float:" << endl;
//     // showMinMax<float>();
//     // cout << "double:" << endl;
//     // showMinMax<double>();
//     // cout << "long double:" << endl;
//     // showMinMax<long double>();
//     // cout << "unsigned short:" << endl;
//     // showMinMax<unsigned short>();
//     // cout << "unsigned int:" << endl;
//     // showMinMax<unsigned int>();
//     // cout << "unsigned long:" << endl;
//     // showMinMax<unsigned long>();
//     int maxIntValue = numeric_limits<int>::max();
//     cout
//         << maxIntValue << endl;
// }

#include <bits/stdc++.h>
using namespace std;
class Test
{
private:
    int a = 10;

public:
    void disp();
};
void Test::disp()
{
    cout << 2 * a << endl;
}

