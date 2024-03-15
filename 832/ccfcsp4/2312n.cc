//https://blog.csdn.net/qq_45123552/article/details/136002427
#pragma GCC optimize(2, 3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define dwn(i, s, t) for(int i=s;i>=t;i--)

const int N = 1e5 + 5;
const int M = 350 + 5;
const int maxn = N;
const int maxb = M;
const int mod = 998244353;
int n, m, t, k, q;

struct mat {
    int v[2][2];

    mat() {//E
        v[0][0] = v[1][1] = 1;
        v[1][0] = v[0][1] = 0;
    }

    mat(bool flag) {
        v[0][0] = v[1][1] = 1;
        v[1][0] = v[0][1] = 0;
    }

    friend mat operator*(const mat &a, const mat &b) {
        mat res;
        res.v[0][0] = (1ll * a.v[0][0] * b.v[0][0] + 1ll * a.v[0][1] * b.v[1][0]) % mod;
        res.v[0][1] = (1ll * a.v[0][0] * b.v[0][1] + 1ll * a.v[0][1] * b.v[1][1]) % mod;
        res.v[1][0] = (1ll * a.v[1][0] * b.v[0][0] + 1ll * a.v[1][1] * b.v[1][0]) % mod;
        res.v[1][1] = (1ll * a.v[1][0] * b.v[0][1] + 1ll * a.v[1][1] * b.v[1][1]) % mod;
        return res;
    }

    friend istream &operator>>(istream &in, mat &x) {
        /*return in >> x.v[0][0] >> x.v[0][1] >> x.v[1][0] >> x.v[1][1];*/
        rep(i, 0, 1) rep(j, 0, 1) in >> x.v[i][j];
        return in;
    }

    friend ostream &operator<<(ostream &out, const mat &x) {
        rep(i, 0, 1) rep(j, 0, 1) out << x.v[i][j] << " ";
        return out;
    }
};

struct node {
    int op;
    mat l, r;

    friend istream &operator>>(istream &in, node &nd) {
        in >> nd.op;
        switch (nd.op) {
            case 1: {
                in >> nd.l, nd.r = mat();
                break;
            }
            case 2: {
                in >> nd.r, nd.l = mat();
                break;
            }
            case 3: {
                nd.l = nd.r = mat();
                break;
            }
        }
        return in;
    }
} op[maxn];

int sn;

struct block {
    /*neg: 未匹配的指令3的条数
     * sz: 栈中剩余的指令个数
     * suml,sumr: 剩余的指令的矩阵的前缀积,注意矩阵乘法的顺序问题
     * */
    int l, r, neg, sz;
    mat suml[maxb], sumr[maxb];

    void build(int idx) {//计算块的前缀积
        l = idx * sn, r = min(l + sn - 1, n - 1), neg = 0, sz = 0;
        deque<int> dq;
        rep(i, l, r) {
            if (op[i].op != 3) dq.push_back(i);
            else if (dq.empty()) ++neg;
            else dq.pop_back();
        }
        sz = dq.size();
        suml[0] = sumr[0] = mat();
        rep(i, 0, sz - 1) {
            suml[i + 1] = op[dq[i]].l * suml[i];
            sumr[i + 1] = sumr[i] * op[dq[i]].r;
        }
    }
} blk[maxb];

mat query(int l, int r) {
    int bl = l / sn, br = r / sn;
    if (bl == br) { // 直接模拟
        deque<int> dq;
        for (int i = l; i <= r; i++)
            if (op[i].op != 3) dq.push_back(i);
            else if (!dq.empty()) dq.pop_back();
        mat L = mat(true), R = mat(true);
        for (int i = 0; i < dq.size(); i++) {
            L = op[dq[i]].l * L;
            R = R * op[dq[i]].r;
        }
        return L * R;
    } else {
        int neg = 0;
        deque<int> dq;
        rep(i, blk[br].l, r) {
            if (op[i].op != 3) dq.push_back(i);
            else if (dq.empty()) neg++;
            else dq.pop_back();
        }
        mat L = mat(true), R = mat(true);
        for (int i = 0; i < dq.size(); i++) {
            L = op[dq[i]].l * L;
            R = R * op[dq[i]].r;
        }

        dwn(i, br - 1, bl + 1) {
            if (blk[i].sz <= neg) neg = neg - blk[i].sz + blk[i].neg;
            else {
                L = L * blk[i].suml[blk[i].sz - neg];
                R = blk[i].sumr[blk[i].sz - neg] * R;
                neg = blk[i].neg;
            }
        }

        while (!dq.empty()) dq.pop_back();
        rep(i, l, blk[bl].r) {
            if (op[i].op != 3) dq.push_back(i);
            else if (!dq.empty()) dq.pop_back();
        }
        while (neg && !dq.empty()) neg--, dq.pop_back();
        dwn(i, dq.size() - 1, 0) {
            L = L * op[dq[i]].l;
            R = op[dq[i]].r * R;
        }
        return L * R;
    }
}

void flow() {
    cin >> n >> m;
    sn = max(1, (int) sqrt(n));
    rep(i, 0, n - 1) cin >> op[i];
    for (int i = 0; i < n; i += sn) blk[i / sn].build(i / sn);
    int v, idx, l, r;
    while (m--) {
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
#ifdef DEBUG
    file(data);
#endif
    int Case = 1;
    //cin >> Case;
    while (Case--) flow();
    return 0;
}