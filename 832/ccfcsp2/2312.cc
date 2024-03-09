/**
 * @file 2312.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/9
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
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define dwn(i, s, t) for(int i=s;i>=t;i--)
#define ite(it, s, e) for(auto it=s;it!=e;++it)
const ll maxi = 1e10 + 1;
const int maxq = 10 + 1;
int q, k;
ll n;

void prime(ll x, map<ll, ll> &mp) {
    int i = 2;
    while (x != 1) {
        if (x % i == 0) {
            x /= i;
            if (mp.find(i) == mp.end()) mp[i] = 1;
            else ++mp[i];
        } else ++i;
    }
}

ll lpow(ll a, ll b) {
    ll tmp = pow(a, b >> 1);
    return b & 1 ? (a * tmp * tmp) : (tmp * tmp);
}

int main() {
    ios::sync_with_stdio(false);
//    file(data);
    cin >> q;
    map<ll, ll> mp;
    while (q--) {
        ll ans = 1;
        cin >> n >> k;
        prime(n, mp);
        for (auto &m: mp) {
            if (m.second >= k) {
                ans *= lpow(m.first, m.second);
            }
        }
        cout << ans << '\n';
        mp.clear();
    }
    return 0;
}