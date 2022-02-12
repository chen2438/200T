```cpp
string d_to_oth(int n,int radix){
	int flag=-1;
	string ans="";
	if(n<0){
		flag=1;
		n=-n;
	}
	do{
		int t=n%radix;
		if(t>=0 and t<=9) ans+=t+'0';
		else ans+=t-10+'A';
		n/=radix;
	}while(n!=0);
	reverse(ans.begin(),ans.end());
	if(flag==1) ans="-"+ans; 
	return ans;	
}
```