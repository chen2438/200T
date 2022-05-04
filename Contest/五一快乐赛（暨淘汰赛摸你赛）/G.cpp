#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define int long long

int pre[200]={0,1,2},sum[200];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	FOR(i,3,100){
		pre[i]=pre[i-2]+pre[i-1];
	}
	FOR(i,1,100){
		sum[i]=sum[i-1]+pre[i];
	}
	
	
	int T;cin>>T;
	while(T--){
		string s;cin>>s;
		int num;cin>>num;
		int numh=0,posj,posx;
		FOR(i,0,s.size()-1){
			if(s[i]=='H'){
				numh++;
			}
			if(s[i]=='J'){//僵尸
				posj=i;
			}
			if(s[i]=='X'){//向日葵
				posx=i;
			}
		}
		int dis=posj-posx;
		/*cout<<"dis="<<dis<<endl;
		cout<<"numh="<<numh<<endl;
		cout<<"pre[dis]*numh="<<pre[dis]*numh<<endl;*/
		
		if(sum[dis]*numh>=num){
			cout<<"0\n";
		}
		else{
			num-=sum[dis]*numh;
			if(num%10==0){
				cout<<num/10<<'\n';
			}
			else{
				cout<<num/10+1<<'\n';
			}
		}
	}


}