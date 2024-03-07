/**01背包问题
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/5
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
int n, v;
const int maxn = 1e3 + 1;
vector<vector<int>> f(maxn, vector<int>(maxn, 0));//记忆化搜索，空间换时间；在第x个物品时剩余surplusV空间时最大价值 [0,n)[0,v]
vector<pii > vw(maxn);//v,w [0,n)
//f:从x~n个物品，总体积<=j的最大价值
int dfs(int x, int surplusV, int sumW) {//RE,讨论到第x个物品
    if (x > n) return 0;
    if (surplusV < vw[x].first) return dfs(x + 1, surplusV, sumW);
    return max(dfs(x + 1, surplusV, sumW), dfs(x + 1, surplusV - vw[x].first, sumW + vw[x].second));
}

int dfs(int i, int j) {
    if (f[i][j]) return f[i][j];//记忆化搜索
    if (i >= n) return 0;
    if (j < vw[i].first) return f[i][j] = dfs(i + 1, j);
    return f[i][j] = max(dfs(i + 1, j), dfs(i + 1, j - vw[i].first) + vw[i].second);
}

int diTuiUp() {//同递归公式
    //from down to up 从叶到根的遍历 逆序递推/枚举
    dwn(i, n - 1, 0) rep(j, 0, v)if (j < vw[i].first) f[i][j] = f[i + 1][j];
            else f[i][j] = max(f[i + 1][j], f[i + 1][j - vw[i].first] + vw[i].second);
    return f[0][v];
}

//f:从1~x个物品，总体积<=j的最大价值
int diTuiDn() {//由于有i-1,故f中i从1开始算
    //from up to down 顺序递推/枚举
    rep(i, 0, n - 1) rep(j, 0, v)if (j < vw[i].first) f[i + 1][j] = f[i][j];
            else f[i + 1][j] = max(f[i][j], f[i][j - vw[i].first] + vw[i].second);
    return f[n][v];
}

int diTuiT() {//优化空间
    //注意到f只用了i,i-1两行
    int ff[maxn] = {0}, cf[maxn] = {0};//上一个状态ff,当前状态cf
    rep(i, 0, n - 1) {//第i个物品
        rep(j, 0, v) {//剩余容量j
            cf[j] = ff[j];
            if (j >= vw[i].first) cf[j] = max(ff[j], ff[j - vw[i].first] + vw[i].second);
        }
        memcpy(ff, cf, sizeof ff);//cf->ff
    }
    return ff[v];
}

int main() {
    ios::sync_with_stdio(false);
    file(data);
    cin >> n >> v;
//    for(auto &o:obj) cin>>o.first>>o.second;
    for (int i = 0; i < n; ++i) cin >> vw[i].first >> vw[i].second;
//    cout << dfs(0, v);
//    cout<<diTuiUp();
//    cout << diTuiDn();
    cout << diTuiT();
    return 0;
}