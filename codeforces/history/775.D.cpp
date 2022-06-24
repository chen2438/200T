// Problem: B. Integral Array
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int mod=1000000007 , N = 1e6 + 10;
const double eps=1e-8;
int a[N],st[N*2];
ll s[N*2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c;
		scanf("%d%d",&n,&c);
		for(int i = 1 ; i <= 2*c ; i ++ )	st[i] = 0;
		for(int i = 1 ; i <= n ; i ++ )
		{
			scanf("%d",&a[i]);
			st[a[i]] =1;
		}
		for(int i = 1 ; i <= 2*c ; i ++ )	s[i] = s[i-1] + st[i];
		bool flag = true;
		for(int i = 1 ; i <= c ; i ++ )
		{	
			if(!st[i])	continue;
			for(int j = 1 ; j * i <= c ; j ++ )
			{
				if(st[j])	continue;
				if(s[i*j-1] != s[i*(j+1)-1])	flag = false;
				//这里区间的右端点最坏取到2*c，所以数组大小开二倍
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
