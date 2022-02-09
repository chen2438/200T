#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;



int bit[20];
int a[1000];
void pb(int val){
	for(int i = 17; i >= 0; i--){
		if(val & (1 << i))
			bit[i]++;
	}
}
 
int main()
{
//	printbinary(2*100000);
	
	/*
	for(int i=17;i>=0;i--){
		cout<<bit[i];
	}
	*/
	int at=1;
	for(int i=0;i<31;i++){
		at<<=1;
		a[i]=at-1;
	//	cout<<a[i]<<" ";
	}
	
	
	int T;
	cin>>T;
	while(T--){
		memset(bit,0,sizeof(bit));
		int l,r;
		cin>>l>>r;
		
		int pl,pr;
		for(int i=0;i<30;i++){
			if(l<a[i]){
				cout<<i<<endl;
				pl=i;
				break;
			}
		}
		for(int i=0;i<30;i++){
			if(r<a[i]){
				cout<<i<<endl;
				pr=i;
				break;
			}
		}
		
		int tt[10],t2[10];
		t2[0]=tt[0]=l-a[pl];
		t2[1]=tt[1]=a[pl+1]-a[pl];
		t2[2]=tt[2]=a[pr]-a[pr-1];
		t2[3]=tt[3]=r-a[pr];
		int t;
		sort(tt,tt+4);
		if(t2[0]==tt[3])t=pl;
		if(t2[1]==tt[3])t=pl+1;
		if(t2[2]==tt[3])t=pr-1;
		if(t2[3]==tt[3])t=pr;
		t--;
			int cnt=0;
			for(int i=l;i<=r;i++){
				if(i & (1 << t))cnt++;
			}
		cout<<cnt;
		cout<<endl;
	}
	
	return 0;
}

