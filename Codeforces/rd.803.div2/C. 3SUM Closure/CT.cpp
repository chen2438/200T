#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	FOR(i,-10,10){
		FOR(j,-10,10){
			FOR(k,-10,10){
				FOR(l,-10,10){
					FOR(m,-10,10){
						if(i+j+k==i or i+j+k==j or i+j+k==k or i+j+k==l or i+j+k==m)
						if(l+j+k==i or l+j+k==j or l+j+k==k or l+j+k==l or l+j+k==m)
						if(i+l+k==i or i+l+k==j or i+l+k==k or i+l+k==l or i+l+k==m)
						if(i+j+l==i or i+j+l==j or i+j+l==k or i+j+l==l or i+j+l==m)
						if(m+j+k==i or m+j+k==j or m+j+k==k or m+j+k==l or m+j+k==m)
						if(i+m+k==i or i+m+k==j or i+m+k==k or i+m+k==l or i+m+k==m)
						if(i+j+m==i or i+j+m==j or i+j+m==k or i+j+m==l or i+j+m==m)
						if(l+m+i==i or l+m+i==j or l+m+i==k or l+m+i==l or l+m+i==m)
						if(l+m+j==i or l+m+j==j or l+m+j==k or l+m+j==l or l+m+j==m)
						if(l+m+k==i or l+m+k==j or l+m+k==k or l+m+k==l or l+m+k==m)
							printf("%d %d %d %d %d\n",i,j,k,l,m);
					}
				}
			}
		}
	}
	
	return 0;
}