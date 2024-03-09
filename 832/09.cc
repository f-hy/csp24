/**
 * @file 09.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/7
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
const int maxn = 1e3 + 1;

void sdu1(int n) {
    int b[maxn] = {0}, halfn = (n << 1) + 1;
    rep(i, 1, halfn) b[i] = b[i - 1] + i;
    rep(i, 1, halfn - 1) rep(j, i + 1, halfn) {
            if (b[j] - b[i - 1] == n) {
                rep(k, i, j) cout << k << ' ';
                cout << '\n';
            }
        }
}

void sdu2() {//UK

}

int main() {
    ios::sync_with_stdio(false);
    //file(data);
    sdu1(21);
    return 0;
}