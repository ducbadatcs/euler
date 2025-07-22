#include <cstdint>
// #include <format>
#include <ios>
#include <iostream>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

using ll = int64_t;
using namespace std;

const int sz = 2e3;
const int mod = 1e6;

unordered_map<ll, ll> s_cache;
ll A[sz][sz];

const vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                    {0, 1},   {1, -1}, {1, 0},  {1, 1}};

ll t = numeric_limits<ll>::min();

ll fpow(ll a, ll b, ll c) {
    ll t = 1;
    while (b) {
        if (b & 1) t = (t * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return t;
}

ll s(ll k) {
    if (s_cache.count(k) > 0) {
        return s_cache[k];
    }

    else {
        if (1 <= k && k <= 55) {
            ll a = fpow(k, 3, mod) * 300007;
            ll b = k * 200003;
            ll c = 100003;
            return s_cache[k] = (c - b + a) % mod - 500000;
        } else {
            return s_cache[k] = (s(k - 24) + s(k - 55) + mod) % mod - 500000;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < sz * sz; i++) {
        A[i / sz][i % sz] = s(i + 1);
    }

    cout << "s(10) = " << s(10) << '\n';
    cout << "s(100) = " << s(100) << '\n';

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            int x = i, y = j;
            int px = x, py = y;
            for (pair<int, int> p : dir) {
                x = px;
                y = py;
                int dx = p.first, dy = p.second;
                ll z = 0;
                while (0 <= x && x < sz && 0 <= y && y < sz) {
                    z += A[x][y];
                    x += dx;
                    y += dy;
                    if (z > t) {
                        cout << "New Max Found at z = " << z
                             << ", at x = " << px << " and y = " << py
                             << " and dir = (" << dx << ", " << dy
                             << ")"
                                "\n";
                        t = z;
                    }
                }
            }
        }
    }

    cout << t;
}
