## [P3879 [TJOI2010] 阅读理解](https://www.luogu.com.cn/problem/P3879)

#### 字典树写法

[参考1](https://www.luogu.com.cn/blog/_post/31110)

[参考2](https://www.luogu.com.cn/blog/_post/82818)

[bitset用法](https://www.cnblogs.com/zwfymqz/p/8696631.html)

[854ms/45.96MB](https://www.luogu.com.cn/record/69304560)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int nex[300007][26],n,cnt=0;
bitset<1001> b[500007];//bool b[500007][1001];

void insert(char* s,int rol){
	int len=strlen(s+1);
    int now=0;
    FOR(i,1,len){
        int p=s[i]-'a';
        if(!nex[now][p])//如果$Trie$树中没有这个单词的前缀就进行编号
			nex[now][p]=++cnt;//上文中说到的编号 
        now=nex[now][p];//接着深入一层，更新现在的位置 
    }
    b[now][rol]=1;//这个单词在第x行出现了
}

void check(char* s){
	int len=strlen(s+1);
    int now=0,flag=1;
    FOR(i,1,len){
        int p=s[i]-'a';
        if(!nex[now][p]){//如果在Trie树中没有当前的字符，就可以直接break掉了 
			flag=0;
			break;
		}
        now=nex[now][p];//否则就更新位置 
    }
    if(flag){
		FOR(i,1,n)//题面上说按字典序输出 
			if(b[now][i]) cout<<i<<" ";//输出在哪些句子中出现过 
    }
    putchar('\n');
}

int main(){
    cin>>n;
    char s[25];
    FOR(i,1,n){
        int l;cin>>l;
        FOR(j,1,l){//一个单词一个单词的插入Trie树里 
        	cin>>(s+1);
			insert(s,i);
        }
    }
    int m;cin>>m;
    FOR(i,1,m){
    	cin>>(s+1);
		check(s);
    }
    return 0;
}
```

#### STL: MAP + VECTOR 写法

[参考](https://www.luogu.com.cn/blog/_post/44774)

用`STL`可以不必纠结数组开多大以及爆空间，但会更费时

[`2.06s/3.96MB`](https://www.luogu.com.cn/record/69303923)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

const int maxn = 100001;
int n,m,num,cnt[maxn];
string s;
map<string,vector<int> >a;

int main(){   
    cin>>n;
    FOR(i,1,n){
        cin>>num;
        FOR(j,1,num){
            cin>>s;
            a[s].push_back(i);//每一个单词就是一个vector,存句子的编号
        }
    }
    cin>>m;
    FOR(i,1,m){
        cin>>s;
        mem(cnt);//cnt就是去重的桶。每用一次输出不同的查询要清零。
        int len=a[s].size();
        FOR(j,0,len-1)
            if(cnt[a[s][j]] == 0){
                cout<<a[s][j]<<" ";
                cnt[a[s][j]]++;//用桶去重
            }
        cout<<endl;
    }
    return 0;
}
```

#### STL: MAP + SET 写法

[参考](https://www.luogu.com.cn/blog/_post/76028)

用`set`可以自动去重，更方便。同时**耗时非常优秀**，仅次于手写`Trie`

[972ms/5.34MB](https://www.luogu.com.cn/record/69305757)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

map<string,set<int> > m;

int main(){
    int n,p,l;
    string s;
    cin>>n;
    FOR(i,1,n){
        cin>>l;//单词个数
        FOR(j,0,l-1){
            cin>>s;//单词
            m[s].insert(i);
        }
    }
    cin>>p;
    while(p--){
        cin>>s;
        if(m.count(s)){//如果m中存在元素s
            for(auto iter=m[s].begin();iter!=m[s].end();++iter)
                cout<<*iter<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```