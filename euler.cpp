#define __USE_MATH_DEFINES
#define debug(x) cout << #x << " = " << x << endl;
#pragma GCC optimize("Ofast", "inline-functions", \
                     "aggressive-loop-optimizations")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
// const char endline = '\n';
using ll = long long;
using ull = unsigned long long;

const ll mod = 1e9 + 7, mod2 = 998244353, maxn = 1e6 + 1, maxn2 = 5e3 + 1;
// all the mods are primes!

ll n, t, k, m, a, b, z, q, c, p, d;
long double g, u, w;
char ch;
ll ar[maxn], br[maxn], cr[maxn];
bool dr[maxn];
string s, x, st, sr;

int __tests__ = 1;
#define __MT__ 0

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    // preprocess
    cr[0] = 1;
    for (int i = 1; i <= 10; ++i) cr[i] = cr[i - 1] * i;

#if __MT__
    cin >> __tests__;
#endif

    // solve
    for (int __jiji__ = 1; __jiji__ <= __tests__; ++__jiji__) {
        z = 0;
        n = (int)1e9;
        for (int i = 3; i <= n; ++i) {
            t = 0;
            p = i;
            a = i;
            while (p > 0) {
                t += cr[p % 10];
                p /= 10;
            }
            if (t == a) {
                cout << i << endl;
                z += i;
            }
        }
        cout << endl << z;
    }

    return 0;
}