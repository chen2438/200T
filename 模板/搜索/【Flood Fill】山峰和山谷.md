## 1106. 山峰和山谷

![image-20220515132305054](https://media.opennet.top/i/2023/01/09/63bb96e87895f.png)

![image-20220515132318553](https://media.opennet.top/i/2023/01/09/63bb96e97ebab.png)

![image-20220515132327362](https://media.opennet.top/i/2023/01/09/63bb96eaa03b3.png)

![image-20220515132337006](https://media.opennet.top/i/2023/01/09/63bb96ebe890e.png)

![image-20220515132344803](https://media.opennet.top/i/2023/01/09/63bb96ecf0707.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1010;

int n;
int h[N][N];
queue<PII> q;
bool st[N][N];

void bfs(int sx, int sy, bool& has_higher, bool& has_lower)
{
    q.push({sx,sy});
    st[sx][sy] = true;

    while (!q.empty())
    {
        PII t = q.front();q.pop();

        for (int i = t.x - 1; i <= t.x + 1; i ++ )
            for (int j = t.y - 1; j <= t.y + 1; j ++ )
            {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (h[i][j] != h[t.x][t.y]) // 山脉的边界
                {
                    if (h[i][j] > h[t.x][t.y]) has_higher  = true;
                    else has_lower = true;
                }
                else if (!st[i][j])
                {
                    q.push({i, j});
                    st[i][j] = true;
                }
            }
    }
}

int main()
{
    cin>>n;

    FOR(i,0,n-1)
        FOR(j,0,n-1)
            scanf("%d", &h[i][j]);

    int peak = 0, valley = 0;
    FOR(i,0,n-1)
        FOR(j,0,n-1)
            if (!st[i][j])
            {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak ++ ;
                if (!has_lower) valley ++ ;
            }
    
    printf("%d %d\n", peak, valley);
    
    return 0;
}
```

