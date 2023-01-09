## 173. 矩阵距离

![image-20220519215845804](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220519215845804.png)

![image-20220519220040432](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220519220040432.png)

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
int dist[N][N];

void bfs()
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    memset(dist, -1, sizeof dist);

    FOR(i,1,n)
        FOR(j,1,m)
            if (g[i][j] == '1')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }

    while (!q.empty())
    {
        auto t = q.front();q.pop();
        FOR(i,0,3)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (dist[a][b] != -1) continue;

            dist[a][b] = dist[t.x][t.y] + 1;
            q.push({a,b});
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%s", g[i] + 1);
    
    bfs();
    
    FOR(i,1,n)
    {
        FOR(j,1,m) printf("%d ", dist[i][j]);
        puts("");
    }

    return 0;
}
```

