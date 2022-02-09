#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;
char matx[60][60]; 
int main(){
	int T;
	cin>>T;
	int n,m,r,c;
	bool posb;
	while(T--){
		mem(matx);
		posb=false;
		cin>>n>>m>>r>>c;
		r--;c--;
		FOR(i,0,n-1){
			FOR(j,0,m-1){
				cin>>matx[i][j];
				if(!posb and matx[i][j]=='B'){
					posb=true;
				}
			}
		}
		
		if(!posb){
			cout<<-1<<endl;
			continue;
		}
		
		if(matx[r][c]=='B'){
			cout<<0<<endl;
			continue;
		}
		
		{
			bool same=false;
			FOR(i,0,n-1){
				if(matx[i][c]=='B'){
					same=true;
					break;
				}
			}
			FOR(i,0,m-1){
				if(matx[r][i]=='B'){
					same=true;
					break;
				}
			}
			if(same){
				cout<<1<<endl;
				continue;
			}
		}
		
		cout<<2<<endl;
	}
}
