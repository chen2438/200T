## 最长不上升序列长度和最长上升序列长度
[P1020 [NOIP1999 普及组] 导弹拦截](https://www.luogu.com.cn/problem/P1020)

[**思路来源**](https://www.luogu.com.cn/blog/w1049/solution-p1020)

**需要注意的点：**
`dp1[i]`的含义：最长不上升子序列长度为`i`时，最优的结尾元素，而不是最长不上升子序列。

**`AC` 代码**
```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=1e5+7;
int a[maxn],dp1[maxn],dp2[maxn];

int main() {
	int n=1;
	while(cin>>a[n]) ++n;
	n--;

	int len1=1,len2=1;
	dp1[1]=a[1];
	dp2[1]=a[1];

	FOR(i,2,n){
		if(dp1[len1]>=a[i]) dp1[++len1]=a[i];
		else{
			int p1=upper_bound(dp1+1,dp1+1+len1,a[i],greater<int>())-dp1;
			dp1[p1]=a[i]; 
		}
		if(dp2[len2]<a[i]) dp2[++len2]=a[i];
		else{
			int p2=lower_bound(dp2+1,dp2+1+len2,a[i],less<int>())-dp2;
			dp2[p2]=a[i];
		}
	}
	cout<<len1<<endl<<len2;
	return 0;
}

```
用记忆化搜索做的 $O(n^2)$ 方法：

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

const int maxn=1e5+7;
int n,a[maxn];
int mem1[maxn],mem2[maxn];

int dfs1(int p){
	if(mem1[p]!=0) return mem1[p];
	int res=1;
	FOR(i,p+1,n)
		if(a[p]>=a[i]) res=max(res,dfs1(i)+1);
	return mem1[p]=res;
}

int dfs2(int p){
	if(mem2[p]!=0) return mem2[p];
	int res=1;
	FOR(i,p+1,n)
		if(a[p]<a[i]) res=max(res,dfs2(i)+1);
	return mem2[p]=res;
}

int main(){
	n=1;
	while(cin>>a[n]) ++n;
	n--;

	ROF(i,n,1){
		dfs1(i);
		dfs2(i);
	}
	int ans1=0,ans2=0;
	FOR(i,1,n){
		ans1=max(ans1,mem1[i]);
		ans2=max(ans2,mem2[i]);
	}
	cout<<ans1<<"\n"<<ans2;;
}
```
## 最长公共子序列长度
[P1439 【模板】最长公共子序列](https://www.luogu.com.cn/problem/P1439)
**转化成最长不下降子序列**


```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

#define map _map
const int maxn=1e5+7;
int a2[maxn],dp[maxn],map[maxn];

int main() {
	int n;cin>>n;
	int x;
	FOR(i,1,n){
		cin>>x;//x=a1[i]
		map[x]=i;//a1[i] -> i
	}
	FOR(i,1,n){
		cin>>x;
		a2[i]=map[x];
	}

	int len=1;
	dp[1]=a2[1];

	FOR(i,2,n){
		if(dp[len]<=a2[i]) dp[++len]=a2[i];
		else{
			int p1=upper_bound(dp+1,dp+1+len,a2[i],less<int>())-dp;
			dp[p1]=a2[i]; 
		}
	}
	cout<<len;
	return 0;
}
```

## 输出最长不下降子序列   $O(n^2)$

```cpp
#include <iostream>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int MAXN = 1007;

int n, a[MAXN],dp[MAXN],from[MAXN];

void output(int x){
    if(!x) return;
    output(from[x]);
    cout<<a[x]<<" ";
}

int main(){
    n=1;
    while(cin>>a[n]) ++n;
    n--;
    FOR(i,1,n){
        dp[i]=1;
        from[i]=0;
        FOR(j,1,i-1){
            if(a[j]<a[i] and dp[i]<dp[j]+1)
                dp[i]=dp[j]+1,from[i]=j;
        }
    }
    
    int ans=dp[1],pos=1;
    FOR(i,1,n){
        if(ans<dp[i]) ans=dp[i],pos=i;
    }
    cout<<"max="<<ans<<endl;
    output(pos);
    return 0;
}
```

## D1. Xor-Subsequence (easy version)

### 标签

动态规划

### 题意

![image-20220820122036398](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208201228198.png)

### 思路

注意 b 数组是 a 的下标序列，我读题的时候以为 b 是 a 的子序列......

![image-20220820122255827](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208201228200.png)

![image-20220820122307130](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202208201228170.png)

限制可以卡到 256 。 

### 代码

```cpp
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(a) cout<<#a<<"="<<a<<endl
#define mem(a) memset((a),0,sizeof(a))
#define endl '\n'
// #define int long long
using namespace std;

const int N = 3e5+7;
int a[N],f[N];

void solve(){
    int n; cin>>n;
    FOR(i,0,n-1){
        f[i]=1;
        cin>>a[i];
    }
    FOR(i,0,n-1){
        FOR(j,max(0,i-256),i-1){
            if((a[j]^i)<(a[i]^j)) f[i]=max(f[i],f[j]+1);
        }
    }
    int ans=0;
    FOR(i,0,n-1) ans=max(ans,f[i]);
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T=1; cin>>T;
    while(T--) solve();
    return 0;
}
```

