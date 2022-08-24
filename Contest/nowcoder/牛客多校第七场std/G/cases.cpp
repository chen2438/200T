#include<bits/stdc++.h>
#define ll long long
using namespace std;

//a . *
string S;
int sn;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int Tcase; cin>>Tcase;
	while(Tcase--)
	{
		cin>>S;
		sn=S.size();
		
		int ans1,ans2;
		if(sn==1)
		{
			ans1=1, ans2=2;
			//a
			//.
		}
		else //sn>=2
		{
			ans1=2;
			ans2=0;
			
			if(sn==2) ans2++; //ab
			
			if(sn==2) ans2++; //a.
			
			int ok=1;
			for(int i=1;i<sn;i++) if(S[i]!=S[i-1]) ok=0;
			ans2+=ok; //a*
			
			ans2+=ok; //a+
			
			if(sn==2) ans2++; //.a
			
			if(sn==2) ans2++; //..
			
			ans2++; //.*
			
			ans2++;//.+
		}
		
		cout<<ans1<<' '<<ans2<<'\n';
	}
	
	return 0;
}
