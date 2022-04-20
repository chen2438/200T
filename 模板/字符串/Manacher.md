## Manacher

**题目描述**

给出一个只由小写英文字符组成的字符串 $S$ ,求 $S$ 中最长回文串的长度 。

字符串长度为 $n$。

**输入格式**

一行小写英文字符组成的字符串 $S$。

**输出格式**

一个整数表示答案。

[P3805 【模板】manacher 算法](https://www.luogu.com.cn/problem/P3805)

[参考](https://12349.blog.luogu.org/manacher-zong-jie)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=3e7;
char s[maxn],st[maxn];
int R[maxn];

int pre_process(){
    int len=strlen(st);
    int j=2;
    s[0]='^';
    s[1]='$';
    FOR(i,0,len-1){
        s[j++]=st[i];
        s[j++]='$';
    }
    s[j]='&';
    return j;
}

int manacher(){
    int len=pre_process();
    int mid=1,RB=1,ans=-1;
    FOR(i,1,len-1){
        if(i<RB) R[i]=min(RB-i,R[mid*2-i]);
        else R[i]=1;
        while(s[i-R[i]]==s[i+R[i]]) R[i]++;
        if(RB<i+R[i]){
            mid=i;
            RB=i+R[i];
        }
        ans=max(ans,R[i]-1);
    }
    return ans;
}

int main(){
    cin>>st;
    cout<<manacher();
    return 0;
}
```