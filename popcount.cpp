// #pragma GCC target("avx2,popcnt")
#include <bit>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    long double d = 0;
    for (long long i = 1; i <= 1e10; ++i) {
        d += 1.0 * (popcount((unsigned long)i) & 1) / (i);
        if (i % 100000000 == 0) {
            cout << "i = " << i << ", d = " << d << endl;
        }
    }
    cout << setprecision(30) << d << endl;
}