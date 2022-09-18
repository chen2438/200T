#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,x;
	cin>>n>>x;
	vector<int> vec;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(not vec.empty() and (vec.back()==t or vec.back()==x-t))vec.pop_back(),cnt++;
		else vec.push_back(t);
	}
	for(int l=0,r=(int)vec.size()-1;l<r;l++,r--)
	{
		if(vec[l]==vec[r] or vec[l]+vec[r]==x)cnt++;
		else break;
	}
	cout<<cnt<<endl;
	
	return 0;
}
