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