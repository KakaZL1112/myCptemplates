// 单点修改，区间查询 查询区间左闭右开 from jiangly
template<class Info>
struct SGT {
    #define l(p) (p << 1)
    #define r(p) (p << 1 | 1)
    int n;
    std::vector<Info> info;
    SGT() {}
    SGT(int _n, Info _v = Info()) {
        init(_n, _v);
    }
    template<class T>
    SGT(std::vector<T> _init) {
        init(_init);
    }
    void init(int _n, Info _v = Info()) {
        init(std::vector(_n, _v));
    }
    template<class T>
    void init(std::vector<T> _init) {
        n = _init.size();
        info.assign(4 << std::__lg(n), Info());
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = _init[l];
                return;
            }
            int m = l + r >> 1;
            self(self, l(p), l, m);
            self(self, r(p), m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) { // 这个就是 y 总的 pushup
        info[p] = info[l(p)] + info[r(p)];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        if (x < m) {
            modify(l(p), l, m, x, v);
        } else {
            modify(r(p), m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y or r <= x) {
            return Info();
        }
        if (l >= x and r <= y) {
            return info[p];
        }
        int m = l + r >> 1;
        return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
    }
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    #undef l(p)
    #undef r(p)
};

struct Info {
    // 定义要存的变量，比如区间和 sum 或者最大公约数 d 等等，至于下标就不用存了
};
Info operator+(Info a, Info b) {
    Info c;
    // 对 a（左儿子） 和 b（右儿子） 一通操作合成 c（父结点）
    return c;
}
/*


struct Info {
    LL sum, d;
    Info(LL s = 0): sum(s), d(s) {}
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.d = std::gcd(a.d, b.d);
    return c;
}

std::vector<Info> a(n);
    for (int i = 0; i < n; i += 1) {
        std::cin >> a[i].d;
    }

*/