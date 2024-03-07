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
ll f[maxn][maxn]={0};//操作数序列剩余待排数i,栈内数j
ll diGui(int i,int j){//递归
    if(f[i][j]) return f[i][j];//使用记忆
    if(!i) return 1;//只有栈中有数
    if(j>0) f[i][j]+=diGui(i,j-1);//1个出栈后可能的结果数
    f[i][j]+=diGui(i-1,j+1);//1个入栈后可能的结果数
    return f[i][j];
}
ll diTui(){//???
    rep(j,0,n) f[0][j]=1;//递推边界
    rep(i,1,n) rep(j,i,n){
        f[i][j]=f[i-1][j];
        if(i!=j) f[i][j]+=f[i][j-1];
    }
    return f[n][n];
}
ll cc(ll x){//catalan f[n]=f[n-1]*(4*n-2)/(n+1)//组合数公式推导
    if(x==1) return 1;
    return cc(x-1)*(4*x-2)/(x+1);
}

int main() {
    ios::sync_with_stdio(false);
    //file(data);
    cin>>n;
//    cout<<cc(n);
//    cout<<diGui(n,0);
    cout<<diTui();
    return 0;
}