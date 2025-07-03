#include <bits/stdc++.h>
// int128 by jiangly
using i128 = __int128;
 
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
 
i128 toi128(const std::string &s) {
    i128 n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}
 
i128 sqrti128(i128 n) {
    i128 lo = 0, hi = 1E16;
    while (lo < hi) {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
using i64 = long long;
using i128 = __int128;

/**   上取整下取整
**/
i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    } else {
        return n / m;
    }
}
 
i64 floorDiv(i64 n, i64 m) {
    if (n >= 0) {
        return n / m;
    } else {
        return (n - m + 1) / m;
    }
}

/**   最大值赋值
**/
template<class T>
void chmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

/**   最大公约数
**/
i128 gcd(i128 a, i128 b) {
    return b ? gcd(b, a % b) : a;
}

/**   精确开平方
**/
i64 sqrt(i64 n) {
    i64 s = std::sqrt(n);
    while (s * s > n) {
        s--;
    }
    while ((s + 1) * (s + 1) <= n) {
        s++;
    }
    return s;
}

/**   精确开平方
**/
i64 get(i64 n) {
    i64 u = std::sqrt(2.0L * n);
    while (u * (u + 1) / 2 < n) {
        u++;
    }
    while (u * (u - 1) / 2 + 1 > n) {
        u--;
    }
    return u;
}

/**   求 Log
**/
int logi(int a, int b) {
    int t = 0;
    i64 v = 1;
    while (v < b) {
        v *= a;
        t++;
    }
    return t;
}
 
int llog(int a, int b) {
    if (a <= b) {
        int l = logi(a, b);
        return (l == 0 ? 0 : std::__lg(2 * l - 1));
    }
    int l = logi(b, a + 1) - 1;
    assert(l > 0);
    return -std::__lg(l);
}

