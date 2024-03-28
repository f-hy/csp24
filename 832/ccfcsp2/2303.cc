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
#pragma GCC optimize(2, 3, "Ofast", "inline")

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
const int ntc = 1e5 + 1;
const int maxm = 1e9 + 1;
int n, m, k, t, c;
map<int, int, greater<int>> tc;

void flow() {
    cin >> n >> m >> k;
    while (n--) {
        cin >> t >> c;
        auto it = tc.find(t);
        if (it == tc.end()) tc[t] = c;
        else it->second += c;
    }
    while (true) {
        c = tc.begin()->second;
        if ((m -= c) >= 0) {
            t = tc.begin()->first;
            auto it = tc.find(t - 1);
            if (it == tc.end()) tc[t - 1] = c;
            else tc[t - 1] += c;
            tc.erase(tc.begin());
        } else break;
    }
    cout << tc.begin()->first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//#undef DEBUG
#ifdef DEBUG
    file(data);
#endif
    flow();
    return 0;
}