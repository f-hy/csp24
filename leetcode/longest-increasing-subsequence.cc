/**
 * @file longest-increasing-subsequence.cc
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
const int maxn = 2500 + 1;
const int maxi = 1e4 + 1;

//第x个数，选中子序列中当前最大值y
int diGui(int x, int y, const vector<int> &nums) {//RE
    if (x >= nums.size()) return 0;
    if (y >= nums[x]) return diGui(x + 1, y, nums);
    return max(diGui(x + 1, y, nums), diGui(x + 1, nums[x], nums) + 1);
}

int diGui(int x, int y, const vector<int> &nums, vector<map<int, int>> &vm) {//Debug可通过,但提交会错
    if (vm[x].find(y) != vm[x].end()) return vm[x].at(y);
    if (x >= nums.size()) return 0;
    if (y >= nums[x]) return vm[x][y] = diGui(x + 1, y, nums, vm);
    return vm[x][y] = max(diGui(x + 1, y, nums, vm), diGui(x + 1, nums[x], nums, vm) + 1);
}

//选择x作为最长递增子序列的结尾
int diGui(int x, const vector<int> &nums, vector<int> &f) {
    if (f[x]) return f[x];
    int res = 0, tmp;
    rep(i, 0, x - 1) if (nums[i] < nums[x]) {
            tmp = diGui(i, nums, f) + 1;
            if (res < tmp) res = tmp;
        }
    return f[x] = res;
}

int diGui(const vector<int> &nums) {
//    return diGui(0, -maxi, nums);
//    vector<map<int, int>> vm(nums.size());//x,y:i
//    return diGui(0, -maxi, nums, vm);
    vector<int> f(nums.size());
    int res = -maxi, tmp;
    rep(i, 0, nums.size() - 1) {//选择i作为最长递增子序列的结尾的结果
        tmp = diGui(i, nums, f);
        if (res < tmp) res = tmp;
    }
    return res + 1;
}

int diTuiUp(const vector<int> &nums) {
    vector<int> f(nums.size(), 0);
    rep(i, 0, nums.size() - 1) {
        rep(j, 0, i - 1) if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
    }//找到所有以i作为最长递增子序列的结尾的序列长结果f
    int res = 0;
    rep(i, 0, nums.size() - 1) if (res < f[i]) res = f[i];//取f的最大值
    return res + 1;
}

int lengthOfLIS(vector<int> &nums) {
//    return diGui(nums);
    return diTuiUp(nums);
}

int main() {
    ios::sync_with_stdio(false);
    file(data);
    vector<int> nums;
    int t;
    while (scanf("%d,", &t) != EOF) {
        nums.emplace_back(t);
    }
    cout << lengthOfLIS(nums);
//    map<int, int> mp;
//    rep(i, -10, 10) mp[i] = i;
//    for (auto &m: mp) {
//        cout << m.first << ' ' << m.second << '\n';
//    }
    return 0;
}