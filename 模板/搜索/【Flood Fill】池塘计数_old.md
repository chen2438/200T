## AcWing 1097. 池塘计数

![image-20220515123433400](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-05-15-044236.png)

![image-20220515124312912](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/2022-05-15-044312.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010;

int n, m;
char g[N][N];
queue<PII> q;
bool st[N][N];

void bfs(int sx, int sy)
{
    q.push({sx,sy});
    st[sx][sy] = true;

    while (!q.empty())
    {
        PII t = q.front();q.pop();
        FOR(i,t.x-1,t.x+1)
            FOR(j,t.y-1,t.y+1)
            {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (g[i][j] == '.' || st[i][j]) continue;

                q.push({i,j});
                st[i][j] = true;
            }
    }
}

int main()
{
    cin>>n>>m;
    FOR(i,0,n-1) scanf("%s", g[i]);

    int cnt = 0;
    FOR(i,0,n-1)
        FOR(j,0,m-1)
            if (g[i][j] == 'W' && !st[i][j])
            {
                bfs(i, j);
                cnt ++ ;
            }

    cout<<cnt;

    return 0;
}
```

