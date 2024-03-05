/**
 * @file 1004.cc
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
const int maxn=18+1;
int n;
/* catalan $f[n]=\C^n_{2n}/(n+1)$
 * f[n]=f[0]*f[n-1]+f[1]*f[n-2]+...+f[n-1]*f[0](n>=2)
 * f[n]=f[n-1]*(4*n-2)/(n+1)//组合数公式推导
 */
ll cc(ll x){
    if(x==1) return 1;
    return cc(x-1)*(4*x-2)/(x+1);
}
int main() {
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
    cout<<cc(n);
    return 0;
}