#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int ok=0;
		vector<int> a(n+5);
		vector<int> p(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=a[1])
				ok=1;
		}
		if(not ok)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int l=1,r=n;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=l)
				p[i]=l,l++;
			else
				p[i]=r,r--;
		}
		p[n]=l;
		if(p[n]==a[n])
		{
			for(int i=1;i<=n-1;i++)
			{
				if(p[n]!=a[i])
				{
					swap(p[n],p[i]);
					break;
				}
			}
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<p[i]<<" \n"[i==n];
		}
	}
	return 0;
}