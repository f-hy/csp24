/**
 * @file 821跳台阶.cpp
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
const int maxn=16;
int n;
int mem[maxn]={0,1,2};
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,3,n){
        mem[i]=mem[i-1]+mem[i-2];
    }
    cout<<mem[n]<<endl;
    return 0;
}