[P3865 【模板】ST 表](https://www.luogu.com.cn/problem/P3865)

[参考1](https://www.luogu.com.cn/blog/_post/31037)

[参考2](https://oi-wiki.org/ds/sparse-table/)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int MAXJ=log2((int)(1e5))+1;//17
const int MAXN=1e6+10;

inline int IntRead(){//快速读入比关闭同步的cin快得多
    char ch=getchar();
    int s=0,w=1;
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0',
        ch=getchar();
    }
    return s*w;
}

int Max[MAXN][17];

int Query(int l,int r){
    int k=log2(r-l+1); 
    return max(Max[l][k],Max[r-(1<<k)+1][k]);//把拆出来的区间分别取最值 
}

int main(){
    int n=IntRead(),m=IntRead();
    FOR(i,1,n)
        Max[i][0]=IntRead();
    FOR(j,1,MAXJ)
        for(int i=1;i+(1<<j)-1<=n;i++)//注意这里要控制边界 
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    FOR(i,1,m){
        int l=IntRead(),r=IntRead();
        printf("%d\n",Query(l,r));
    }
    return 0;
}
```