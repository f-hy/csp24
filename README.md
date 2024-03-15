OJS

- https://vjudge.net/problem/{title}
- http://poj.org/problem?id={title}
- https://www.luogu.com.cn/problem/P{title}
- https://www.acwing.com/problem/content/{title}
- https://leetcode.cn/problems/{title}
- http://118.190.20.162/home.page\\(http://118.190.20.162/view.page?gpid=T{ID})

net,legacy

[202312-4 宝藏](https://blog.csdn.net/qq_45123552/article/details/136002427)

#### 题解

- [栈](https://www.luogu.com.cn/problem/solution/P1044)catalan

  当前出栈序列最后一个为x,则$x\in\{1..n\}$,三组a{1..x-1},b{x},c{x+1..n}(aabccb),a出栈可能数为f[x-1],c出栈可能为f[n-x],故有可能数为`f[x-1]*f[n-x]`,

  $f[n]=f[0]*f[n-1]+f[1]*f[n-2]+...+f[n-1]*f[0](n\ge2)\\=\frac{C^n_{2n}}{n+1}=f[n-1]*\frac{4n-2}{n+1}(组合数公式推导)$



#### DP

做题步骤:重述问题,找到最后一步,(去掉最后一步)划分子问题,考虑边界[列出公式,考虑边界]

[动态规划(dp)入门bilibili](https://www.bilibili.com/video/BV1r84y1379W/)[动态规划入门](https://www.luogu.com.cn/paste/xac615na)

子问题拆分至可直接解决,记忆化子答案(减少重复计算),再推得解

记忆化搜索 = 暴力dfs + 记录答案

dfs,记忆化搜索,逆序递推/枚举,顺序递推/枚举,优化空间,滚动数组

递(分解子问题)归(产生答案)

递推:公式(dfs向下递归的公式),数组的初始值(递归的边界)





[LCR 091. 粉刷房子](https://leetcode.cn/problems/JEj789/) 简单dp

[413\. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices/) 如果满足等差，则f\[i\] = f\[i - 1\] + 1, 否则为0

[279\. 完全平方数](https://leetcode.cn/problems/perfect-squares/) 简单预处理，最后一步：选择某个数作为最后一个

[91\. 解码方法](https://leetcode.cn/problems/decode-ways/) 正序dfs好写

[646\. 最长数对链](https://leetcode.cn/problems/maximum-length-of-pair-chain/) 最长上升子序列模板 + 排序

[918\. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/) 找找最大和 、 最小和 和 总和的关系

[376\. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/) 考虑相邻两个数大小问题，枚举选哪个模型，dp转移可以直接**01转移**

[2786\. 访问数组中的位置使分数最大](https://leetcode.cn/problems/visit-array-positions-to-maximize-score/) 枚举每个数选或不选，记录上的数的奇偶性，**01转移** 实现dfs不需要传vector的参数

[213\. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/) 考虑选不选第一个物品，可以把问题分为两个子问题

[122\. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) 状态机模型

[368\. 最大整除子集](https://leetcode.cn/problems/largest-divisible-subset/) pre数组**记录路径**，更新时实现记录，而不是以前的max不知道更新没更新

[1105\. 填充书架](https://leetcode.cn/problems/filling-bookcase-shelves/) 枚举选哪个，**转移方程**有教学意义

[1416\. 恢复数组](https://leetcode.cn/problems/restore-the-array/) 枚举选哪个，**集合转移**

[2466\. 统计构造好字符串的方案数](https://leetcode.cn/problems/count-ways-to-build-good-strings/) 爬楼梯

[1043\. 分隔数组以得到最大和](https://leetcode.cn/problems/partition-array-for-maximum-sum/) 枚举选哪个，**集合转移**

[2400\. 恰好移动 k 步到达某一位置的方法数目](https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) 要对mem数组做偏移，`mem[now + N][cnt]` ，选其中一个的思路

[1335\. 工作计划的最低难度](https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/) 枚举选哪个思路，**集合转移**

[7006\. 销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/) **集合转移**， 预处理endi，选或不选

[2008\. 出租车的最大盈利](https://leetcode.cn/problems/maximum-earnings-from-taxi/) 选或不选

[1235\. 规划兼职工作](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/) 选或不选 [1751\. 最多可以参加的会议数目 II](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/) 类似 [2054\. 两个最好的不重叠活动](https://leetcode.cn/problems/two-best-non-overlapping-events/)

转移

[376\. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/) 考虑相邻两个数大小问题，枚举选哪个模型，dp转移可以直接01转移

[2786\. 访问数组中的位置使分数最大](https://leetcode.cn/problems/visit-array-positions-to-maximize-score/) 枚举每个数选或不选，记录上的数的奇偶性

[122\. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) 状态机模型

[1186\. 删除一次得到子数组最大和](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/) 子数组最大和 + 记录删没删

[2369\. 检查数组是否存在有效划分](https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/) **划分型dp** 好像用不了记忆化搜索？

[2466\. 统计构造好字符串的方案数](https://leetcode.cn/problems/count-ways-to-build-good-strings/) 爬楼梯

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 

#### 