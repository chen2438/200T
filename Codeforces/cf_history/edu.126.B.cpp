#include<bits/stdc++.h>
#define int long long
//#define double long double

using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define push_back emplace_back

const int C = 32768;
vector<int> G[C];
int dis[C];

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  for(int i = 0; i < C; i++) {
    G[(2 * i) % C].push_back(i);
    G[(i + 1) % C].push_back(i);
  }

  fill(dis, dis + C, INT_MAX);
  queue<int> q;
  q.push(0);
  dis[0] = 0;

  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int X : G[now])
      if (dis[X] == INT_MAX) {
        dis[X] = dis[now] + 1;
        q.push(X);
      }
  }

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int val; cin >> val;
    cout << dis[val] <<" \n"[i==n-1];
  }

  return 0;
}