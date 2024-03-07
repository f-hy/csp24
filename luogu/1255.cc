/**60
 * @file 1255.cc
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
const int maxn=5e3+1;
int n;

ll f[maxn]={0, 1, 2};
int main() {
    ios::sync_with_stdio(false);
    file(data);
    cin>>n;
    rep(i,3,n){
        f[i]= f[i - 1] + f[i - 2];
    }
    rep(i,1,n) cout << f[i] << " ";
    cout << f[n] << endl;
    return 0;
}