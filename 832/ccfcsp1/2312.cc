/**暴力
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
const int maxn = 1e3 + 1;
const int maxm = 1e1 + 1;
const int maxi = 1e6 + 1;
int n, m;

void print(vector<int> vec) {
    for (auto &v: vec) cout << v << ' ';
    cout << '\n';
}

bool cmp(const vector<int> &a, const vector<int> &b) {//a<b
    int n = a.size();
    rep(i, 0, n - 1) {
        if (a[i] >= b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
//    file(data);
    cin >> n >> m;
    vector<vector<int>> vv(n + 1, vector<int>(m, 0));
    rep(i, 1, n) rep(j, 0, m - 1) cin >> vv[i][j];
    rep(i, 1, n) {
        bool prt = false;
        rep(j, 1, n) {
            if (i == j) continue;
            if (cmp(vv[i], vv[j])) {
                cout << j << '\n';
                prt = true;
                break;
            }
        }
        if (!prt) cout << "0\n";
    }
    return 0;
}