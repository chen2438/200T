#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int dy=11,hr=11,mi=11;

int main(){
	int d,h,m;
	cin>>d>>h>>m;
	dy-=d;hr-=h;mi-=m;
	int ans=dy*24*60+hr*60+mi;
	if(ans<=0)cout<<-ans;
	else cout<<-1;
	return 0;
}

