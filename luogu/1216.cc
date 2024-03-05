/**
 * @file 1216.cc
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
int r;
const int maxr=1e3+1;
vector<int> mem(maxr,0),p(maxr,0),tri(maxr,0);
int main() {
    ios::sync_with_stdio(false);
    file(data);
    cin>>r;cin>>p[1];//共r行
    for(int i=2;i<=r;++i){//第i行
        for(int j=1;j<=i;++j) cin>>tri[j];//输入第i行
        mem[1]=p[1]+tri[1];//计算第1列
        for(int j=2;j<i;++j) mem[j]= tri[j]+max(p[j-1],p[j]);
        mem[i]=p[i-1]+tri[i];//计算第i列
//        for(int j=1;j<=i;++j) cout<<mem[j]<<' ';
//        cout<<endl;
        mem.swap(p);
    }
    int ans=0;
    for(int i=1;i<=r;++i) if(ans<p[i]) ans=p[i];
    cout<<ans<<endl;
    return 0;
}