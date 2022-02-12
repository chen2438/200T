[P3375 【模板】KMP字符串匹配](https://www.luogu.com.cn/problem/solution/P3375)

[参考](https://fanfansann.blog.csdn.net/article/details/107555602)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N=1000007;

int nex[N];
char a[N],b[N];

int main(){
    cin>>(b+1)>>(a+1);//A:模式串;B:文本串
    int lena=strlen(a+1),lenb=strlen(b+1);
    nex[1]=0;

    int j;
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