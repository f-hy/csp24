/**
 * @file test.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/4
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
#define mem(x, i) memset(x,i,sizeof(x))

template<class T=char>
ll _tmem(T x, int n) {
    ll res = x;
    while (n--) {
        res = (res << 8) + 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    // file(data);
#ifdef DEBUG
    cout << "test" << endl;
#endif
    ll x[1 << 2];
    mem(x, 1);
    for (int i = 1; i <= 3; i++) cout << x[i] << " \n"[i == 3];
    return 0;
}