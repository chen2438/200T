### [P3375 【模板】KMP字符串匹配](https://www.luogu.com.cn/problem/P3375)

#### 题目描述

![image-20220420154035185](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-04-20-074035.png)

#### 代码

[参考](https://fanfansann.blog.csdn.net/article/details/107555602)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N=1000007;

int nex[N];
char a[N],b[N];

int main(){
    scanf("%s%s",b+1,a+1);
    //cin>>(b+1)>>(a+1);//A:模式串;B:文本串
    int lena=strlen(a+1),lenb=strlen(b+1);
    nex[1]=0;

    int j=0;
    FOR(i,2,lena){//A串自己匹配
        while(j>0 and a[i]!=a[j+1]) j=nex[j];
        if(a[i]==a[j+1]) j++;
        nex[i]=j;
    }
    for(int i=1,j=0;i<=lenb;++i){//A串向B串匹配
        while(j>0 and b[i]!=a[j+1]) j=nex[j];
        if(b[i]==a[j+1]) j++;
        if(j==lena) cout<<i-lena+1<<"\n",j=nex[j];
    }
    FOR(i,1,lena)
        cout<<nex[i]<<" ";
    return 0;
}
```

### AcWing 831. KMP字符串

#### 题目描述

![image-20220728095315777](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-28-015316.png)

#### 代码

```cpp
#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main(){
    cin >> n >> p + 1 >> m >> s + 1;//下标从1开始
    for (int i = 2, j = 0; i <= n; i ++ ){//预处理next指针数组
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++ ){//kmp匹配
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n){
            printf("%d ", i - n);//答案下标从0开始
            j = ne[j];
        }
    }
    return 0;
}
```

