/**
 * @file 2303.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/19
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
#define x .first
#define y .second
int n, a, b, res = 0;
pii l, r;

void flow() {
    cin >> n >> a >> b;
    while (n--) {
        cin >> l x >> l y >> r x >> r y;
        if (l x < a && l y < b && r x > 0 && r y > 0) {
            res += ((min(a, r x) - max(0, l x)) * (min(b, r y) - max(0, l y)));
        }
    }
    cout << res;
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