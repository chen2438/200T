#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main() {
	sync_with_stdio(0);
   string s ;
   cin >> s ;
   string ss = s + s ;
   reverse(ss.begin(), ss.end()) ;
   cout << (ss.find(s) != string::npos) << endl ;
}
