/**0
 * @file 2309.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/16
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2024
 */
#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mem(x, i) memset(x, i, sizeof(x))
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define dwn(i, s, t) for(int i=s;i>=t;i--)
#define ite(it, s, e) for(auto it=s;it!=e;++it)
#define cinarr(a, n) for (int i = 1; i <= n; i++) cin >> a[i]
#define coutarr(a, n) for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n]
#define cinstl(a) for (auto& x : a) cin >> x;
#define coutstl(a) for (const auto& x : a) cout << x << ' '; cout << '\n'
#define md(x) (((x) % mod + mod) % mod)
#define be(x) (x).begin(), (x).end()
const int maxn = 1e5 + 1;
const int maxi = 1e6 + 1;
int n, m, op, ii, jj;
double sumk[maxn] = {1.}, sumc[maxn] = {1.}, k, x, y, kk, cc, ox, oy;


void flow() {
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> op >> k;
        if (op == 1) {
            sumk[i] = k * sumk[i - 1];
            sumc[i] = sumc[i - 1];
        } else {
            sumk[i] = sumk[i - 1];
            sumc[i] = k + sumc[i - 1];
        }
    }
    while (m--) {
        cin >> ii >> jj >> x >> y;
        kk = sumk[jj] / sumk[ii - 1];
        cc = sumc[jj] - sumc[ii - 1];
        x *= kk, y *= kk;
        ox = x * cos(cc) - y * sin(cc);
        oy = x * sin(cc) + y * cos(cc);
        cout << fixed << setprecision(3) << ox << ' ' << oy << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    file(data);
#endif
    flow();
    return 0;
}