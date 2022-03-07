#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define scan(a) scanf("%d",&(a))
#define abss(x) ((x)>(0)?(x):(-1)*(x))
using namespace std;

const int maxn=1e3+7;
const int maxm=1e5+7;

set<int> s;

struct node{
    int x,y;
};

vector<node> v[maxm];


int main(){
    v[0].push_back({1,2});
    cout<<v[0].x<<" "<<v[0].y<<'\n';
    return 0;
}