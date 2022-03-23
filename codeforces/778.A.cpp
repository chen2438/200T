#include <bits/stdc++.h>
 
using namespace std;
 
void solve( ) {
  int  n; cin >> n;
  vector<int>a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  cout << (a[n-2] + a[n-1]) << "\n";
}

int main(void) {
  int tt;cin>>tt;
  while(tt--)
  solve();
  return 0;
}