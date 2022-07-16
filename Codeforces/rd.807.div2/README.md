# [Codeforces Round #807 (Div. 2)](https://codeforces.com/contest/1705)

## 提交情况

![image-20220716143706280](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-063707.png)

![image-20220716143713673](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-063713.png)

## 参考

[Codeforces Round #807 (Div. 2) A~E](https://zhuanlan.zhihu.com/p/542170898)

## A. Mark the Photographer

### 标签

构造

### 题意

![image-20220716130029246](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-050029.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

void solve(){
	int n,x;cin>>n>>x;
	int a[1007]={};
	FOR(i,1,2*n) cin>>a[i];
	sort(a+1,a+2*n+1);
	int ans=1;
	FOR(i,1,n) if(a[i+n]-a[i]<x) ans=0;
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
```

## B. Mark the Dust Sweeper

### 标签

构造

### 题意

![image-20220716130245696](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-050246.png)

### 思路

把前导零去除, 然后把剩余的 0 填充为 1, 每次填充花费 1 个操作数, 填充完后依次把所有非零值加到 a[n].

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
int a[200007];

void solve(){
	int n;cin>>n;
	FOR(i,1,n) cin>>a[i];
	int st=1;
	while(a[st]==0) st++;
	int ans=0;
	FOR(i,st,n-1){
		if(a[i]==0) ans++;
		else ans+=a[i];
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
```

## C. Mark and His Unfinished Essay

### 标签

构造, 二分, 递归

### 题意

![image-20220716130632640](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-050632.png)

### 思路

参考 [C. Sereja and Prefixes](https://github.com/chen2438/200T/tree/main/Codeforces/rd.223.div2/C.%20Sereja%20and%20Prefixes).

以前出过的题目.

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long

struct node{
    int prel,prer,l,r;
};

vector<node> a;
char s[200007];

int n;

int ask(int k){
    int l=0,r=a.size()-1;
    while(l<r){
        int mid=(l+r)/2;
        if(k<a[mid].l) r=mid-1;
        else l=mid+1;
    }
    if(a[r].r<=n) return k;
    else{
        int nk=a[r].prel+k-a[r].l;
        return ask(nk);
    }
    return -1;
}

void solve(){
    a.clear();
    memset(s,0,sizeof s);
    int c,q;
    cin>>n>>c>>q;
    FOR(i,1,n) cin>>s[i];
    int len=n;
    a.push_back({1,n,1,n});
    FOR(i,1,c){
        int l,r;cin>>l>>r;
        a.push_back({l,r,len+1,len+1+r-l});
        len=len+1+r-l;
    }
    FOR(i,1,q){
        int k;cin>>k;
        cout<<s[ask(k)]<<endl;
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
```

## D. Mark and Lightbulbs

### 标签

构造

### 题意

![image-20220716140527342](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-060527.png)

### 思路

![image-20220716140722218](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-16-060722.png)

**重点是把每次操作看作一个连续相同数字段的端点的移动.**

### 代码

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long

struct node{
    int l,r;
};

const int N = 2e5+7;
string s1,s2;
vector<node> n1,n2;

int solve(){
    n1.clear(); n2.clear();
    int n;cin>>n;
    cin>>s1>>s2;
    if(s1==s2) return 0;
    if(s1[0]!=s2[0] or s1[n-1]!=s2[n-1]) return -1;
    FOR(i,0,n-1){
        while(i<=n-1 and s1[i]=='0') i++;
        if(i==n) break;
        int l=i;
        while(i<=n-1 and s1[i]!='0') i++;
        n1.push_back({l,i-1});
    }
    FOR(i,0,n-1){
        while(i<=n-1 and s2[i]=='0') i++;
        if(i==n) break;
        int l=i;
        while(i<=n-1 and s2[i]!='0') i++;
        n2.push_back({l,i-1});
    }
    if(n1.size()!=n2.size()) return -1;
    int ans=0;
    FOR(i,0,n1.size()-1){
        ans+=abs(n1[i].l-n2[i].l)+abs(n1[i].r-n2[i].r);
    }
    return ans;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--) cout<<solve()<<endl;
    return 0;
}
```

