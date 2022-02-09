#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
int n,k;
int a[MAXN];
ll sum1, sum2;
void RunCase()
{
    sum1 = 0;
    sum2 = -inf;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)
        scanf("%d",a+i);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    if(n==k || a[1]==a[n])
    {
        puts("huaiqilaile");
        return;
    }
    for(int i = 1; i <= k; ++i)
        sum1 += a[i];
    if(a[k+1] == a[k])
    {
        for(int i = k; i >= 1; --i)
        {
            if(a[i] != a[k])
            {
                sum2 = sum1-a[i]+a[k+1];
                break;
            }
        }
    }
    for(int i = k+1; i <= n; ++i)
    {
        if(a[i] != a[k])
        {
            sum2 = max(sum2, sum1-a[k]+a[i]);
            break;
        }
    }
    printf("%lld %lld\n", sum1, sum2);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 1; i <= T; ++i) RunCase();
    return 0;
}
