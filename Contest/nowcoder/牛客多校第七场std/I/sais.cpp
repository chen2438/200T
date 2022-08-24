/*program by mangoyang*/
#pragma GCC optimize("Ofast", "inline")
#include<bits/stdc++.h>
#define inf ((ll) 1e18)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int ch = 0, f = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define fi first
#define se second
const int N = 1000005;
vector<int> ch[27];
char s[N];
int t[N];
int sa[N], Lpos[N], Rpos[N], buf[N], n, m, k;
struct suffix_array {
  int sa[N], pos[N];
  int st[21][N];
  int Log[N];
  const int *ht = st[0];

  void sais(const int *a, int *sa, int n, int w) {
    bool *type = new bool[n];
    int *buc = new int[w], *pl = new int[w], *pr = new int[w];
    int n1 = 0, *p1;
    type[n - 1] = true;
    for (int i = n - 1; i; --i) {
      type[i - 1] = a[i - 1] == a[i] ? type[i] : a[i - 1] < a[i];
      n1 += type[i] && !type[i - 1];
    }
    p1 = new int[n1];
    for (int i = 1, *p = p1; i < n; ++i)
      if (type[i] && !type[i - 1]) *(p++) = i;

    memset(buc, 0, sizeof(int) * w);
    for (int i = 0; i < n; ++i)
      ++buc[a[i]];
    for (int i = 0, sum = 0; i < w; ++i) {
      sum += buc[i];
      pr[i] = sum; pl[i] = sum - buc[i];
    }

    auto induce = [&]() {
      memcpy(buc, pl, sizeof(int) * w);
      for (int i = 0; i < n; ++i)
        if (int j = sa[i] - 1; j >= 0 && !type[j]) sa[buc[a[j]]++] = j;
      memcpy(buc, pr, sizeof(int) * w);
      for (int i = n - 1; i >= 0; --i)
        if (int j = sa[i] - 1; j >= 0 && type[j]) sa[--buc[a[j]]] = j;
    };

    memset(sa, -1, sizeof(int) * n);
    memcpy(buc, pr, sizeof(int) * w);
    for (int i = 1; i < n; ++i)
      if (type[i] && !type[i - 1]) sa[--buc[a[i]]] = i;
    induce();

    int id = 0;
    int *s1 = new int[n1], *sa1 = new int[n1];
    for (int i = 0, *p = sa1; i < n; ++i)
      if (type[sa[i]] && sa[i] && !type[sa[i] - 1]) *(p++) = sa[i];
    sa[sa1[0]] = 0;
    for (int i = 0; i < n1 - 1; ++i) {
      int p = sa1[i], q = sa1[i + 1];
      if (a[p] != a[q]) {
        sa[q] = ++id;
        continue;
      }
      ++p, ++q;
      while (a[p] == a[q] && type[p] == type[q] && !(type[p] && !type[p - 1]) && !(type[q] && !type[q - 1]))
        ++p, ++q;
      id += !((type[p] && !type[p - 1]) && (type[q] && !type[q - 1]));
      sa[sa1[i + 1]] = id;
    }
    for (int i = 0; i < n1; ++i)
      s1[i] = sa[p1[i]];

    if (id + 1 == n1)
      for (int i = 0; i < n1; ++i)
        sa1[s1[i]] = i;
    else
      sais(s1, sa1, n1, id + 1);

    memcpy(buc, pr, sizeof(int) * w);
    memset(sa, -1, sizeof(int) * n);
    for (int i = n1 - 1; i >= 0; --i)
      sa[--buc[a[p1[sa1[i]]]]] = p1[sa1[i]];
    induce();
    delete[] type; delete[] buc; delete[] pl; delete[] pr; delete[] p1; delete[] s1; delete[] sa1;
  }

  void init(int *s, int n) {
    int *a = new int[n + 1];
    copy(s, s + n, a);
    a[n] = 0;
    sais(a, sa, n + 1, 200000);
    delete[] a;

    for (int i = 1; i <= n; ++i)
      pos[sa[i]] = i;
    int h = 0;

    for (int i = 0; i < n; ++i) {
      h = !h ? 0 : h - 1;
      int j = sa[pos[i] - 1];
      while (s[i + h] == s[j + h]) ++h;
      st[0][pos[i]] = h;
    }

    for(int i = 1, li = __lg(n); i <= li; ++i)
      for(int j = 1, li = n - (1 << i) + 1; j <= li; ++j)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  	
	for(int i = 2; i < N; i++) Log[i] = Log[i>>1] + 1;
  }

  int lcp(int i, int j) {
    i = pos[i], j = pos[j];
    if (i > j) swap(i, j);
    int k = Log[j - i];
    return min(st[k][i + 1], st[k][j - (1 << k) + 1]);
  }
}S;
int pri[N], rk[N][27], fir[N][27], a[N][27], apos[27][N], cpos[N];
inline bool comp(int x, int y){
	if(pri[x] + pri[y] == 0) return x < y; 
	if(pri[x] == 0) return 0;
	if(pri[y] == 0) return 1;
	return pri[x] < pri[y];
	
}
inline int Getlcp(int p, int q){
	int ans = min(n - p + 1, n - q + 1);
	for(int i = 0; i < k; i++){
		int ci = a[p][i], cj = a[q][i];
		if(fir[p][ci] + fir[q][cj] == 0) break;
		if(fir[q][cj] == 0){
			ans = min(ans, fir[p][ci] - p);
			break;
		}
		if(fir[p][ci] == 0){
			ans = min(ans, fir[q][cj] - q);
			break;
		}
		if(fir[p][ci] - p != fir[q][cj] - q){
			ans = min(ans, fir[p][ci] - p);
			ans = min(ans, fir[q][cj] - q);
			break;
		}
		int ei = cpos[fir[p][ci]], ej = cpos[fir[q][cj]];
		int di = Lpos[ci] + ei - 1, dj = Lpos[cj] + ej - 1;
		int llcp = (di > Rpos[ci] || dj > Rpos[cj]) ? 0 : S.lcp(di, dj);
		if(di + llcp <= Rpos[ci]){
			ans = min(ans, apos[ci][ei+llcp+1] - p);
		}
		if(dj + llcp <= Rpos[cj]){
			ans = min(ans, apos[cj][ej+llcp+1] - q);
		}
	}
	return ans;
}
inline bool cmp(int i, int j){
	int len_lcp = Getlcp(i, j);
	if(i + len_lcp > n) return 1;
	if(j + len_lcp > n) return 0;
	int x = s[i+len_lcp], y = s[j+len_lcp];
	return rk[i][x-'a'] < rk[j][y-'a'];
}

int main(){
	read(n), k = 26;
	m = -1;
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++){
		ch[s[i]-'a'].push_back(i);
		apos[s[i]-'a'][++apos[s[i]-'a'][0]] = i;
	}
	for(int i = 0; i < k; i++){ 
		Lpos[i] = m + 1;
		for(int j = 1; j < (int) ch[i].size(); j++)
			t[++m] = ch[i][j] - ch[i][j-1];
		Rpos[i] = m;
	}
	if(m > 0) S.init(t, m + 1);
	for(int i = 1; i <= n; i++) sa[i] = i;
	for(int i = 1; i <= n; i++)
		cpos[i] = ++buf[s[i]-'a'];
	for(int i = n; i >= 1; i--){
		pri[s[i]-'a'] = i;
		for(int j = 0; j < k; j++)
			a[i][j] = j, fir[i][j] = pri[j];
		sort(a[i], a[i] + k, comp);
		for(int j = 0; j < k; j++) rk[i][a[i][j]] = j;
	}
	sort(sa + 1, sa + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		printf("%d", sa[i]);
		if(i < n) putchar(' ');
	}
	return 0;
}
