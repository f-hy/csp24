/**
 * @file min-cost-climbing-stairs.cc
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

int diGui(int x, const vector<int> &cost) {//RE
    if (x == 0 || x == 1) return 0;
    return min(diGui(x - 1, cost) + cost[x - 1], diGui(x - 2, cost) + cost[x - 2]);
}

int diGui(int x, const vector<int> &cost, vector<int> &f) {
    if (f[x] != -1) return f[x];//记忆化搜索
    if (x == 0 || x == 1) return 0;
    return f[x] = min(diGui(x - 1, cost, f) + cost[x - 1], diGui(x - 2, cost, f) + cost[x - 2]);
}

int diGui(const vector<int> &cost) {
//    return diGui(cost.size(), cost);
    vector<int> f(cost.size() + 1, -1);//需要f[n];cost可以为0
    return diGui(cost.size(), cost, f);
}

int diTuiUp(const vector<int> &cost) {//acwing821
    vector<int> f(cost.size() + 1, 0);
    rep(i, 2, cost.size()) f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
    return f.back();
}

int diTuiSa(const vector<int> &cost) {//滚动数组
    int a = 0, b = 0, c = 0;
    rep(i, 2, cost.size()) {
        c = min(b + cost[i - 1], a + cost[i - 2]);
        a = b;
        b = c;
    }
    return c;
}

int minCostClimbingStairs(vector<int> &cost) {
//    return diTuiUp(cost);
//    return diGui(cost);
    return diTuiSa(cost);
}

int main() {
    ios::sync_with_stdio(false);
    //file(data);
    return 0;
}