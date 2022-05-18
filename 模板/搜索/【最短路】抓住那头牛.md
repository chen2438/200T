## 1100. 抓住那头牛

![image-20220518193440068](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220518193440068.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 1e5 + 10;

int n, k;
queue<int> q;
int dist[N];

int bfs()
{
    memset(dist, -1, sizeof dist);
    dist[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        int t = q.front();q.pop();

        if (t == k) return dist[k];

        if (t + 1 < N && dist[t + 1] == -1)
        {
            dist[t + 1] = dist[t] + 1;
            q.push(t + 1);
        }
        if (t - 1 >= 0 && dist[t - 1] == -1)
        {
            dist[t - 1] = dist[t] + 1;
            q.push(t - 1);
        }
        if (t * 2 < N && dist[t * 2] == -1)
        {
            dist[t * 2] = dist[t] + 1;
            q.push(t * 2);
        }
    }

    return -1;
}

int main()
{
    cin >> n >> k;
    cout << bfs() << endl;
    return 0;
}
```

