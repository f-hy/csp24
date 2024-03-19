/**
 * @file 2305.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/17
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
const int maxn = 1e4 + 1;
const int maxd = 21;
#define nd [maxn][maxd]
int qkt[maxn][maxn] = {0},  q nd, k nd;
ll n, d, w[maxn], ans;

void flow() {
    cin >> n >> d;
    rep(i, 0, n - 1)rep(j, 0, d - 1) cin >> q[i][j];
    rep(i, 0, n - 1)rep(j, 0, d - 1) cin >> k[i][j];
    rep(i, 0, n - 1)rep(j, 0, n - 1)rep(l, 0, d - 1) qkt[i][j] += (q[i][l] * k[j][l]);
    rep(i, 0, n - 1)rep(j, 0, d - 1) cin >> q[i][j];//q: actual v
    rep(i, 0, n - 1) cin >> w[i];
    rep(i, 0, n - 1)rep(j, 0, d - 1) {
            ans = 0;
            rep(l, 0, n - 1) ans += (1ll * qkt[i][l] * q[l][j]);
            cout << ans * w[i] << " \n"[j == d - 1];
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