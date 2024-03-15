//https://blog.csdn.net/qq_45123552/article/details/136002427
#pragma GCC optimize(2, 3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define pii pair<int, int>

const int N = 1e5 + 5;
const int M = 350 + 5;
const int mod = 998244353;
//const int mod = 1e9 + 7;
//template <typename T> T ksm(T a, i64 b) { T ans = 1; for (; b; a = 1ll * a * a, b >>= 1) if (b & 1) ans = 1ll * ans * a; return ans; }
//template <typename T> T ksm(T a, i64 b, T m = mod) { T ans = 1; for (; b; a = 1ll * a * a % m, b >>= 1) if (b & 1) ans = 1ll * ans * a % m; return ans; }

//int a[N];
int n, m, t, k, q;

struct mat {
    int v[2][2];

    mat(bool isE = false) {
        v[0][0] = v[1][1] = isE;
        v[1][0] = v[0][1] = 0;
    }

    friend mat operator*(const mat &a, const mat &b) {
        mat ans;
        ans.v[0][0] = (1ll * a.v[0][0] * b.v[0][0] + 1ll * a.v[0][1] * b.v[1][0]) % mod;
        ans.v[0][1] = (1ll * a.v[0][0] * b.v[0][1] + 1ll * a.v[0][1] * b.v[1][1]) % mod;
        ans.v[1][0] = (1ll * a.v[1][0] * b.v[0][0] + 1ll * a.v[1][1] * b.v[1][0]) % mod;
        ans.v[1][1] = (1ll * a.v[1][0] * b.v[0][1] + 1ll * a.v[1][1] * b.v[1][1]) % mod;
        return ans;
    }

    friend istream &operator>>(istream &in, mat &x) {
        return in >> x.v[0][0] >> x.v[0][1] >> x.v[1][0] >> x.v[1][1];
    }

    friend ostream &operator<<(ostream &out, const mat &x) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                out << x.v[i][j] << " ";
        return out;
    }
};

struct node {
    int op;
    mat l, r;

    friend istream &operator>>(istream &in, node &nd) {
        in >> nd.op;
        if (nd.op == 1) in >> nd.l, nd.r = mat(true);
        else if (nd.op == 2) in >> nd.r, nd.l = mat(true);
        else nd.l = nd.r = mat(true);
        return in;
    }
} op[N];

int sn;

struct block {
    int l, r, neg, sz;
    mat suml[M], sumr[M];

    void build(int idx) {
        l = idx * sn, r = min(l + sn - 1, n - 1), neg = 0, sz = 0;
        deque<int> st;
        for (int i = l; i <= r; i++) {
            if (op[i].op != 3) st.push_back(i);
            else if (st.empty()) neg++;
            else st.pop_back();
        }
        sz = st.size();
        suml[0] = sumr[0] = mat(true);
        for (int i = 0; i < st.size(); i++) {
            suml[i + 1] = op[st[i]].l * suml[i];
            sumr[i + 1] = sumr[i] * op[st[i]].r;
        }
    }
} blk[M];

mat query(int l, int r) {
    int blkl = l / sn, blkr = r / sn;
    if (blkl == blkr) { // 直接模拟
        deque<int> st;
        for (int i = l; i <= r; i++)
            if (op[i].op != 3) st.push_back(i);
            else if (!st.empty()) st.pop_back();
        mat L = mat(true), R = mat(true);
        for (int i = 0; i < st.size(); i++) {
            L = op[st[i]].l * L;
            R = R * op[st[i]].r;
        }
        return L * R;
    } else {
        int neg = 0;
        deque<int> st;
        for (int i = blk[blkr].l; i <= r; i++) {
            if (op[i].op != 3) st.push_back(i);
            else if (st.empty()) neg++;
            else st.pop_back();
        }
        mat L = mat(true), R = mat(true);
        for (int i = 0; i < st.size(); i++) {
            L = op[st[i]].l * L;
            R = R * op[st[i]].r;
        }

        for (int i = blkr - 1; i >= blkl + 1; i--) {
            if (blk[i].sz <= neg) neg = neg - blk[i].sz + blk[i].neg;
            else {
                L = L * blk[i].suml[blk[i].sz - neg];
                R = blk[i].sumr[blk[i].sz - neg] * R;
                neg = blk[i].neg;
            }
        }

        while (!st.empty()) st.pop_back();
        for (int i = l; i <= blk[blkl].r; i++) {
            if (op[i].op != 3) st.push_back(i);
            else if (!st.empty()) st.pop_back();
        }
        while (neg && !st.empty()) neg--, st.pop_back();
        for (int i = st.size() - 1; i >= 0; i--) {
            L = L * op[st[i]].l;
            R = op[st[i]].r * R;
        }
        return L * R;
    }
}

void work() {
    cin >> n >> m;
    sn = max(1, (int) sqrt(n));

    for (int i = 0; i < n; i++) cin >> op[i];
    for (int i = 0; i < n; i += sn) blk[i / sn].build(i / sn);

    while (m--) {
        int v, idx, l, r;
        cin >> v;
        if (v == 1) {
            cin >> idx;
            cin >> op[--idx];
            blk[idx / sn].build(idx / sn);
        } else {
            cin >> l >> r;
            cout << query(--l, --r) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    //cin >> Case;
    while (Case--) work();
    return 0;
}