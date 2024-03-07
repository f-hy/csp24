/**
 * @file house-robber.cc
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
int rob(vector<int>& nums) {
    vector<int> mem(nums.size()+1,0);
//    mem.at(1)=nums.at(0);
//    for(int i=1;i<nums.size();++i){
//        mem.at(i+1)=max(mem.at(i),mem.at(i-1)+nums.at(i));
//    }
    mem[1]=nums[0];
    for(int i=1;i<nums.size();++i){
        mem[i+1]=max(mem[i],mem[i-1]+nums[i]);
    }
    return mem.back();
}
int main() {
    vector<int> arr = {1,2,3,1};
    cout<<rob(arr);
    return 0;
}