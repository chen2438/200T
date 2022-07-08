https://codeforces.com/group/qWc0vtZbjV/contest/389/problem/C

### 标签

贪心

### 题意

给定 n 个盒子. 第 i 个盒子上最多可以放 x[i] 个盒子, 但只能一个一个堆叠, 一个盒子上不能同时直接放两个盒子.

![img](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-08-024742.png)

把这 n 个盒子堆成几个堆, 求最小堆数.

### 思路

对 x[i] 排序, 从小到大开始构建 1 个堆, 能放则放.

注意从大到小不行.

原理待证明.

