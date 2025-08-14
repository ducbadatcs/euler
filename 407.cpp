#include <bit>
#include <cstdint>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

tuple<u64, u64, u64> extended_euclidean(u64 a, u64 b) {
    u64 s = 0, o_s = 1, r = b, o_r = a;
    while (r != 0) {
        u64 q = o_r / r;
        tie(o_r, r) = make_tuple(r, o_r - q * r);
        tie(o_s, s) = make_tuple(s, o_s - q * s);
    }

    u64 b_t = (b != 0 ? (o_r - o_s * a) / b : 0);
    return make_tuple(o_s, b_t, o_r);
}

u64 crt_2(tuple<u64, u64> a, tuple<u64, u64> m) {
    u64 a1, a2, m1, m2, n1, n2, dummy;
    tie(a1, a2) = a;
    tie(m1, m2) = m;
    tie(n1, n2, dummy) = extended_euclidean(m1, m2);
    u64 t = (a1 * n2 * m2 + a2 * n1 * m1);
    return (t + (m1 * m2)) % (m1 * m2);
}

tuple<u64, u64> fulldiv(u64 n, u64 d) {
    u64 t = 0;
    while (n % d == 0) {
        t += 1;
        n /= d;
    }
    return make_tuple(t, n);
}

tuple<u64, u64> st(u64 n) {
    if (n % 2 == 0) {
        return fulldiv(n, 2);
    } else if (n % 3 == 0) {
        return fulldiv(n, 3);
    }

    u64 i = 5;

    while (i <= n) {
        if (n % i == 0) {
            return fulldiv(n, i);
        } else if (n % (i + 2) == 0) {
            return fulldiv(n, i + 2);
        }
        i += 6;
    }
}
