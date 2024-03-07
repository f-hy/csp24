/**小A点菜
 * @file 1164.cc
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
const int maxm=1e4+1;
const int maxn=1e2+1;
const int maxa=1e3+1;
int n,m;
int a[maxn]={0},f[maxn][maxm]={0};
int diGui(int x,int surplusM){//01背包问题
    if(f[x][surplusM]) return f[x][surplusM];//记忆
    if(!surplusM) return 1;//花光
    if(x>=n) return 0;//没菜了
    if(surplusM<a[x]) return f[x][surplusM]=diGui(x + 1, surplusM);//买不起a[x]
    return f[x][surplusM]= diGui(x + 1, surplusM) + diGui(x + 1, surplusM - a[x]);//买得起a[x]
}
int main() {
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n>>m;
    rep(i,0,n-1) cin>>a[i];
    cout<<diGui(0,m);
    return 0;
}