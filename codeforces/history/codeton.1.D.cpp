#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		ll x = n;
		while(x % 2 == 0) x /= 2;
		if(x == 1) {
			cout << -1 << endl;
		}
		else if(x <= 2e9 && (x*(x+1))/2 <= n) {
			cout << x << endl;
		}
		else {
			cout << 2*(n/x) << endl;
		}
	}
}