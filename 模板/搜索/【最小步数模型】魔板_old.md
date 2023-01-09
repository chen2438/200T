## 1107. 魔板

![image-20220519222732052](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220519222732052.png)

![image-20220519222749318](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220519222749318.png)

![image-20220519222802968](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/image-20220519222802968.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

#define set _set
char g[2][4];
unordered_map<string, pair<char, string>> pre;
unordered_map<string, int> dist;

void set(string state)
{
    FOR(i,0,3) g[0][i] = state[i];
    for (int i = 7, j = 0; j < 4; i --, j ++ ) g[1][j] = state[i];
}

string get()
{
    string res;
    FOR(i,0,3) res += g[0][i];
    ROF(i,3,0) res += g[1][i];
    return res;
}

string move0(string state)
{
    set(state);
    FOR(i,0,3) swap(g[0][i], g[1][i]);
    return get();
}

string move1(string state)
{
    set(state);
    int v0 = g[0][3], v1 = g[1][3];
    ROF(i,3,0)
    {
        g[0][i] = g[0][i - 1];
        g[1][i] = g[1][i - 1];
    }
    g[0][0] = v0, g[1][0] = v1;
    return get();
}

string move2(string state)
{
    set(state);
    int v = g[0][1];
    g[0][1] = g[1][1];g[1][1] = g[1][2];g[1][2] = g[0][2];g[0][2] = v;
    return get();
}

int bfs(string start, string end)
{
    if (start == end) return 0;

    queue<string> q({start});
    dist[start] = 0;

    while (!q.empty())
    {
        auto t = q.front();q.pop();

        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);

        FOR(i,0,2)
            if (!dist.count(m[i]))
            {
                dist[m[i]] = dist[t] + 1;
                pre[m[i]] = {'A' + i, t};
                q.push(m[i]);
                if (m[i] == end) return dist[end];
            }
    }

    return -1;
}

int main()
{
    string start="12345678", end;
    FOR(i,0,7)
    {
        int x;cin >> x;
        end += char(x + '0');
    }

    int step = bfs(start, end);
    cout << step << endl;

    string res;
    while (end != start)
    {
        res += pre[end].first;
        end = pre[end].second;
    }

    reverse(res.begin(), res.end());

    if (step > 0) cout << res << endl;

    return 0;
}
```

