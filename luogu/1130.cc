/**红牌
 * @file 1130.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/6
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
const int maxn = 2e3 + 1;
const int maxa = 1e6 + 1;
int n, m;//步数,小组数
int a[maxn][maxn], f[maxn][maxn];//n,m
int diGui(int i, int j) {//n,m
    if (f[i][j]) return f[i][j];//记忆
    if (!i) return 0;//第0步
    return f[i][j] = a[i][j] + min(diGui(i - 1, j), j == 1 ? diGui(i - 1, m) : diGui(i - 1, j - 1));
}

int diGui() {
    int ans = INT_MAX, tmp;
    rep(j, 1, m) {
        tmp = diGui(n, j);
        if (ans > tmp) ans = tmp;
    }
    return ans;
}

int diTui() {
    rep(i, 1, n) rep(j, 1, m) f[i][j] = min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
    int ans = INT_MAX;
    rep(j, 1, m) if (ans > f[n][j]) ans = f[n][j];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
//    file(data);
    cin >> n >> m;
    rep(j, 1, m) rep(i, 1, n) cin >> a[i][j];
    cout << diGui();
//    cout<<diTui();
    return 0;
}