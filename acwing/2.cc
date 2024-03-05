/**
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
vector<vector<int>> mem(maxn, vector<int>(maxn, 0));//记忆化搜索，空间换时间；在第x个物品时剩余surplusV空间时最大价值
vector<pii > obj(maxn);//v,w
int dfs(int x, int surplusV, int sumW) {//RE,讨论到第x个物品
    if (x > n) return 0;
    if (surplusV < obj[x].first) return dfs(x + 1, surplusV, sumW);
    return max(dfs(x + 1, surplusV, sumW), dfs(x + 1, surplusV - obj[x].first, sumW + obj[x].second));
}

int dfs(int x, int surplusV) {
    if (mem[x][surplusV]) return mem[x][surplusV];//记忆化搜索
    if (x >= n) return 0;
    if (surplusV < obj[x].first) return mem[x][surplusV] = dfs(x + 1, surplusV);
    return mem[x][surplusV] = max(dfs(x + 1, surplusV), dfs(x + 1, surplusV - obj[x].first) + obj[x].second);
}

int main() {
    ios::sync_with_stdio(false);
//    file(data);
    cin >> n >> v;
//    for(auto &o:obj) cin>>o.first>>o.second;
    for (int i = 0; i < n; ++i) cin >> obj[i].first >> obj[i].second;
    cout << dfs(0, v) << endl;
    return 0;
}