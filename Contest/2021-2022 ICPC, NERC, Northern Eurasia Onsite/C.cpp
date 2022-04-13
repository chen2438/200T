#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
using namespace std;
 
struct pt{
	int x,y;
	bool operator<(const pt &_t)const{
        return x<_t.x;
    }
};
struct qt{
	int x,y;
	bool operator<(const qt &_t)const{
        return y<_t.y;
    }
};
 
struct ANS{
	int x,y;
};
 
signed main(){
	//cin.tie(0)->sync_with_stdio(0);
	pt p[4];qt q[4];
	int xmin=INT_MAX,xmax=INT_MIN,ymin=INT_MAX,ymax=INT_MIN;
	FOR(i,1,3){
		int x,y;cin>>x>>y;
		p[i]={x,y};
		q[i]={x,y};
		/*xmin=min(xmin,p[i].x);
		xmax=max(xmax,p[i].x);
		ymin=min(ymin,p[i].y);
		ymax=max(ymax,p[i].y);*/
	}
	sort(p+1,p+4);
	sort(q+1,q+4);
	vector<ANS> ans;
	int midx=p[2].x,midy=q[2].y;
	
	FOR(i,1,3){
		int x=p[i].x,y=p[i].y;
		if(x!=midx and y!=midy){
			ans.push_back({midx,midy});
			ans.push_back({midx,y});
			ans.push_back({midx,y});
			ans.push_back({x,y});
		}
		else if(x!=midx){
			ans.push_back({midx,midy});
			ans.push_back({x,midy});
		}
		else if(y!=midy){
			ans.push_back({midx,midy});
			ans.push_back({midx,y});
		}
	}
	
	cout<<ans.size()/2<<'\n';
	for(int i=0;i<=ans.size()-1;i+=2){
		//if(i.x1==i.x2 and i.y1==i.y2)continue;
		printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i+1].x,ans[i+1].y);
	}
	return 0;
}