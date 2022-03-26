#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

const int maxn (1e5+7);
const int INF (1<<30);

long long f[maxn];

int a(int x){
    return (3*x*x-x)/2;
}
int main()
{
 int n,p;
 cin>>n>>p;
 f[0]=1;
 for(int i=1;i<=n;i++)
  for(int j=1;;j++)
  {
   int x=a(j),y=a(-j);
   if(x<=i)
    f[i]=((f[i]+(j&1?1:-1)*f[i-x])%p+p)%p;
   if(y<=i)
    f[i]=((f[i]+(j&1?1:-1)*f[i-y])%p+p)%p;
   if(x>i||y>i)break;
  }
 cout<<f[n]<<endl;
 return 0;
}