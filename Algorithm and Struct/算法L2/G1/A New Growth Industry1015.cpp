#include<iostream>
#define LL long long
using namespace std;
int d[17],a[25][25],tmp[25][25];

void init(){
	for(int i=0;i<=24;i++){
		for(int j=0;j<=24;j++){
			a[i][j]=0;
			tmp[i][j]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		int day;cin>>day;
		for(int i=0;i<=15;i++)
			cin>>d[i];
		for(int i=1;i<=20;i++)
			for(int j=1;j<=20;j++)
				cin>>a[i][j];
		while(day--){
			for(int i=1;i<=20;i++)
				for(int j=1;j<=20;j++)
					tmp[i][j]=a[i-1][j]+a[i+1][j]+a[i][j]+a[i][j+1]+a[i][j-1];
			for(int i=1;i<=20;i++){
				for(int j=1;j<=20;j++){
					a[i][j]+=d[tmp[i][j]];
					if(a[i][j]>3)a[i][j]=3;
					if(a[i][j]<0)a[i][j]=0;
				}
			}
		}
		for(int i=1;i<=20;i++){
			for(int j=1;j<=20;j++){
				if(a[i][j]==0)cout<<".";
				if(a[i][j]==1)cout<<"!";
				if(a[i][j]==2)cout<<"X";
				if(a[i][j]==3)cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
