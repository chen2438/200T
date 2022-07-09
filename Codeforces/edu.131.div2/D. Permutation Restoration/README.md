https://codeforces.com/contest/1701/problem/D

### 标签

取整不等式, 贪心, 排列

### 题意

有一个排列 a 和数组 b, 定义 $ b_i = \lfloor \frac{i}{a_i} \rfloor$.

现在给定 b, 求出任意一个符合条件的 a.

题目保证有解.

### 思路

$由于\  b_i = \lfloor \frac{i}{a_i} \rfloor $

$即\ b_i \leq \frac{i}{a_i} \lt b_i+1$ 

$所以\ \frac{i}{b_i+1} \lt a_i \leq \frac{i}{b_i} $

我们为每个 i 创建一个节点:

```cpp
struct node{
	int a,b,l,r,dif,index;
};//a[i], b[i], l<=a[i]<=b[i], r-l, i
```

`dif ` 为 a[i] 可选择的区间左右差值, dif 越小, 可选择的范围越小.

我们贪心的从 dif 最小的节点开始, 每次选择区间内的最小值即可.